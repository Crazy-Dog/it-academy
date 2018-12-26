#include <iostream>

void foo(int [] b)
{
	return;
}

int main()
{
	int a[5] = {1,2,3,4,5};
	foo(a);
	std::cout << a << std::endl;
}
