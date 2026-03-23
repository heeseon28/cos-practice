#include <iostream>

int main(int argc, char *argv[]){
	int x{};
	std::cout << "Enter a number: ";
	std::cin >> x;
	if(x > 0){
		std::cout << "You entered a positive interger! " << std::endl;
	} else if (x == 0){
		std::cout << "You entered 0!" << std::endl;
		} else{
			std::cout << "You entered a negative interger! " << std::endl;
		}
		return 0;
}
