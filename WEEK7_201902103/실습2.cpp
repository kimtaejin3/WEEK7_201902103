#include <iostream>

void funcA() {
	int c;
	std::cout << "input(number) : ";
	std::cin >> c;
	if (c < 10) //Let's assume this is exception
		throw std::out_of_range("Invalid input!!");
}

int main() {

	

	try
	{
		funcA();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what();
	}

	return 0;
}


