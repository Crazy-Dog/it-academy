#include <iostream>

int min(int, int);
int min(int, int, int);

int main()
{
	int a1, a2, a3;
	std::cout << "Enter a1: ";
	std::cin >> a1;
	std::cout << "Enter a2: ";
	std::cin >> a2;
	std::cout << "Enter a3: ";
	std::cin >> a3;
	
	std::cout << min(a1, a2, a3) << std::endl;
	
	return 0;
}
