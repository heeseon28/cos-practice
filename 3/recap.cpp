#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int a, b;
	int result = 0;
	cout << "Please enter a : ";
	cin >> a;
	cout << "Plese enter b : ";
	cin >> b;
	if(a < b){
		for(int i = a; i <= b;i++){
			result += i;
			}
		cout << result << endl;
	}
	return 0;
}
