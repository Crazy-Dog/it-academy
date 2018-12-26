#include <iostream>

class A
{
	int b;
public:
	A(int n) 
	{
		b = n;
	}
	~A(){}
	int get() {return b;}
	bool operator<(A obj)
	{
		return (b < obj.b);
	}
};

int main()
{
	A ob1(1);
	A ob2(9);
	std::cout << (ob1 < ob2) << std::endl;
}
