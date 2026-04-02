#include <cstdio>
#include <cstdlib>
#include <cstring>

#define BIT_VECTOR_LENGTH 4
#define MSB_INDEX (BIT_VECTOR_LENGTH - 1)
#define LSB_INDEX 0

void print_command(char *argv[]);
int check_validity(char *input);
void init_bit_vector(char *input, char *bv);
void print_bit_vector(char *bv);
unsigned int b2u(char *bv);
int b2s(char *bv);
int b2o(char *bv);
int b2t(char *bv);

void bit_addition(char *bv1, char *bv2, char *result);
unsigned int unsigned_addition(char *bv1, char *bv2);
int twos_complement_addition(char *bv1, char *bv2);
int ones_complement_addition(char *bv1, char *bv2);
int sign_magnitude_addition(char *bv1, char *bv2);

void print_command(char *argv[])
{
    printf("Command: %s <first bit vector> <second bit vector>\n", argv[0]);
    printf("Example: %s 0110 1000\n", argv[0]);
    exit(1);
}

int check_validity(char *input)
{
    size_t len = strlen(input);
    if (len != BIT_VECTOR_LENGTH)
    {
        return 0;
    }

    for (int i = 0; i < BIT_VECTOR_LENGTH; i++)
    {
        if (!(input[i] == '0' || input[i] == '1'))
        {
            return 0;
        }
    }
    return 1;
}

void init_bit_vector(char *input, char *bv)
{
    for (int i = 0; i < BIT_VECTOR_LENGTH; i++)
    {
        if (input[i] == '0')
            bv[MSB_INDEX - i] = 0;
        else
            bv[MSB_INDEX - i] = 1;
    }
}

void print_bit_vector(char *bv)
{
    for (int i = MSB_INDEX; i >= LSB_INDEX; i--)
    {
        printf("%d", bv[i]);
    }
    printf("\n");
}

unsigned int b2u(char *bv)
{
    unsigned int ret = 0;
    for (int i = LSB_INDEX; i <= MSB_INDEX; i++)
    {
        ret += ((unsigned int)bv[i] << i);
    }
    return ret;
}

// sign-magnitude
int b2s(char *bv)
{
    int ret = 0;
    for (int i = LSB_INDEX; i <= MSB_INDEX - 1; i++)
    {
        ret += (bv[i] << i);
    }

    if (bv[MSB_INDEX] == 1)
    {
        ret *= -1;
    }

    return ret;
}

// one's complement
int b2o(char *bv)
{
    int ret = (-1) * bv[MSB_INDEX] * ((1 << MSB_INDEX) - 1);

    for (int i = LSB_INDEX; i <= MSB_INDEX - 1; i++)
    {
        ret += (bv[i] << i);
    }
    return ret;
}

// two's complement
int b2t(char *bv)
{
    int ret = (-1) * bv[MSB_INDEX] * (1 << MSB_INDEX);

    for (int i = LSB_INDEX; i <= MSB_INDEX - 1; i++)
    {
        ret += (bv[i] << i);
    }
    return ret;
}

void bit_addition(char *bv1, char *bv2, char *result)
{
    int c = 0;

    for (int i = LSB_INDEX; i <= MSB_INDEX; i++)
    {
        int s = bv1[i] + bv2[i] + c;

        if (s == 0)
        {
            result[i] = 0;
            c = 0;
        }
        else if (s == 1)
        {
            result[i] = 1;
            c = 0;
        }
        else if (s == 2)
        {
            result[i] = 0;
            c = 1;
        }
        else // s == 3
        {
            result[i] = 1;
            c = 1;
        }
    }
}

unsigned int unsigned_addition(char *bv1, char *bv2)
{
    char result[BIT_VECTOR_LENGTH];
    bit_addition(bv1, bv2, result);
    return b2u(result);
}

int twos_complement_addition(char *bv1, char *bv2)
{
    char result[BIT_VECTOR_LENGTH];
    bit_addition(bv1, bv2, result);
    return b2t(result);
}

int ones_complement_addition(char *bv1, char *bv2)
{
    char result[BIT_VECTOR_LENGTH];
    bit_addition(bv1, bv2, result);
    return b2o(result);
}

int sign_magnitude_addition(char *bv1, char *bv2)
{
    char result[BIT_VECTOR_LENGTH];
    bit_addition(bv1, bv2, result);
    return b2s(result);
}

int main(int argc, char *argv[])
{
    char bv1[BIT_VECTOR_LENGTH];
    char bv2[BIT_VECTOR_LENGTH];

    if (argc != 3)
    {
        printf("Error: invalid number of arguments\n");
        print_command(argv);
    }

    if (!(check_validity(argv[1]) && check_validity(argv[2])))
    {
        printf("Error: invalid arguments\n");
        print_command(argv);
    }

    init_bit_vector(argv[1], bv1);
    init_bit_vector(argv[2], bv2);

    print_bit_vector(bv1);
    printf(" - B2U: %u\n", b2u(bv1));
    printf(" - B2S: %d\n", b2s(bv1));
    printf(" - B2O: %d\n", b2o(bv1));
    printf(" - B2T: %d\n", b2t(bv1));

    print_bit_vector(bv2);
    printf(" - B2U: %u\n", b2u(bv2));
    printf(" - B2S: %d\n", b2s(bv2));
    printf(" - B2O: %d\n", b2o(bv2));
    printf(" - B2T: %d\n", b2t(bv2));

    printf("Addition >>>\n");
    printf(" - Unsigned addition: %u\n", unsigned_addition(bv1, bv2));
    printf(" - Sign magnitude addition: %d\n", sign_magnitude_addition(bv1, bv2));
    printf(" - One's complement addition: %d\n", ones_complement_addition(bv1, bv2));
    printf(" - Two's complement addition: %d\n", twos_complement_addition(bv1, bv2));

    return 0;
}