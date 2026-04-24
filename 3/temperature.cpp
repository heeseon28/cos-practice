#include <iostream>
using namespace std; // 이거 안들어가있었음

int main(int argc, char *argv[])
{
int fahr, celsius;
int lower, upper, step;
lower = atoi(argv[1]);
upper = atoi(argv[2]);
step = atoi(argv[3]);
fahr = lower; // 세미콜론은 필수

 while (fahr <= upper) {
celsius = 5 * (fahr - 32) / 9; // 변수 명 오류
 std::cout << "fahr: " << fahr << "\tcelsius: " << celsius << endl;
 fahr = fahr + step;
 }
 return 0;
}
