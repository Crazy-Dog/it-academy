#include <iostream>

struct Circle
{
	double r;
};

void swap(Circle * a, Circle * b)
{
	Circle tmp = *a;
	*a = *b;
	*b = tmp;
}
int main()
{
	Circle obj1;
	obj1.r = 123;
	Circle obj2;
	obj2.r = 5;
	
	swap(&obj1, &obj2);
	
	std::cout << "Radius of 1 object: " << obj1.r << std::endl
		<< "Radius of 1 object: " << obj2.r << std::endl;
	
	return 0;
}
