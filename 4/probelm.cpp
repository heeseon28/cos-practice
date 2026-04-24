#include <iostream>
using namespace std;

int check_validity(int a, int b) {
    if (b > a) {
        return 1;
    } else {
        return 0;
    }
}

int sum_up(int a, int b) {
    int sum = 0;

    for (int i = a; i <= b; i++) {
        sum += i;
    }

    return sum;
}

int main(int argc, char *argv[]) {
    int first;
    int second;

    cout << "Enter first number: ";
    cin >> first;

    cout << "Enter second number: ";
    cin >> second;

    if (check_validity(first, second) == 1) {
        int result = sum_up(first, second);
        cout << "Sum: " << result << endl;
    } else {
        cout << "Invalid input. The second number must be bigger than the first number." << endl;
    }

    return 0;
}