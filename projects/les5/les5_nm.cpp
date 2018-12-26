#include <iostream>

class Array
{
	unt *p;
public:
	Array(int num) 
	{
		p = new int[num];
	}
	void set(int i, int v) 
	{
		p[i] = v;
	}
	int get(int i) 
	{
		return p[i];
	}
	~Array() 
	{
		delete [] p
	}	
};
