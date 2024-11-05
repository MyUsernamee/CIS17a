#include <iostream>

bool divByTen(int input) {

	return (input % 10) == 0;

}

int main () {

	std::cout << "Please enter a number" << std::endl;
	int a;
	std::cin >> a;

	std::cout << "Your number ";

	if (divByTen(a)) 
		std::cout << "is ";
	else
		std::cout << "is not ";

	std::cout << "divisible by ten" << std::endl;

}
