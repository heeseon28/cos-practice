#include <iostream>
#include <cstring>

using namespace std;

int uadd_ok(unsigned a, unsigned b){
	unsigned sum = a + b;
	return sum >= a;
}

int tadd_ok(int a, int b){
	int sum = a + b;
	if (a > 0 && b > 0 && sum < 0)
		return 0;
	if (a < 0 && b < 0 && sum > 0)
		return 0;
	return 1;
}

int main(int argc, char *argv[]){
	int a, b;
	unsigned x, y;

	if(argc != 3){
		cout << "Insert 2 number!" << endl;
		return 0;
	}

	a = strtol(argv[1], NULL, 16);
	b = strtol(argv[2], NULL, 16);
	x = (unsigned) a;
	y = (unsigned) b;

	cout << "Unsigned addition ===" << endl;
	if (uadd_ok(x, y))
		cout << "No overflow" << endl;
	else
		cout << "overFlow" << endl;
	cout << "signed addition === " << endl;
	if (tadd_ok(x,y))
		cout << "No overflow" << endl;
	else
		cout << "Overflow" << endl;
	return 0;

}
