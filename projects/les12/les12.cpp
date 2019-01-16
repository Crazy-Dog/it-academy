#include <iostream>

template<typename T>
class Ptr
{
	int * p;
public:
	Ptr() 
	{
		p = NULL;
	}
	Ptr(T * p_) 
	{
		p = p_;
	}
	~Ptr()
	{
		delete p;
	}
	T operator* () 
	{
		return *p;
	}
};

int main()
{
	Ptr<int> p_obj(new int(7));
	std::cout << *p_obj << std::endl;
}
