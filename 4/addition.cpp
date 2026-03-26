#include <iostream>
#include <cstdlib>   // strtol 사용을 위해 필요
#include <climits>   // INT_MAX, INT_MIN 사용을 위해 필요

using namespace std;

// unsigned 덧셈에서 overflow가 발생했는지 검사하는 함수
// unsigned는 overflow가 나면 값이 다시 작은 값으로 돌아간다.
// 따라서 a + b의 결과(sum)가 원래 a보다 작아졌다면 overflow가 난 것.
int uadd_ok(unsigned a, unsigned b){
    unsigned sum = a + b;
    return sum >= a;   // 참이면 overflow 없음, 거짓이면 overflow 발생
}

// signed(int) 덧셈에서 overflow가 발생했는지 검사하는 함수
// int끼리 직접 더해서 overflow가 나면 C++에서 UB가 될 수 있으므로
// 더 큰 자료형(long long)으로 계산해서 범위를 확인한다.
int tadd_ok(int a, int b){
    long long sum = (long long)a + (long long)b;
    return (sum <= INT_MAX && sum >= INT_MIN);
}

int main(int argc, char *argv[]){
    int a, b;          // signed 해석용 변수
    unsigned x, y;     // unsigned 해석용 변수

    // 프로그램 실행 시 숫자 2개를 꼭 입력해야 한다.
    if(argc != 3){
        cout << "Insert 2 numbers!" << endl;
        return 0;
    }

    // 문자열을 16진수로 읽어서 정수로 변환
    a = strtol(argv[1], NULL, 16);
    b = strtol(argv[2], NULL, 16);

    // 같은 비트 패턴을 unsigned로도 해석하기 위해 형변환
    x = (unsigned)a;
    y = (unsigned)b;

    // unsigned 덧셈 overflow 검사
    cout << "Unsigned addition ===" << endl;
    if (uadd_ok(x, y))
        cout << "No overflow" << endl;
    else
        cout << "Overflow" << endl;

    // signed 덧셈 overflow 검사
    cout << "Signed addition ===" << endl;
    if (tadd_ok(a, b))   // 여기서는 int인 a, b를 넣어야 맞다
        cout << "No overflow" << endl;
    else
        cout << "Overflow" << endl;

    return 0;
}
