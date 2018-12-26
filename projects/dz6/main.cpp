#include "m_stack.hpp"

int main()
{
	Stack<int> test;
	test.push(10);
	test.push(11);
	test.push(4242);
	std::cout << test.pop() << std::endl 
		<< test.pop() << std::endl 
		<< test.pop() << std::endl;
	test.push(33);
	std::cout << test.pop() << std::endl;
	test.push(432423);
	test.push(756);
	std::cout << test.pop() << std::endl;
	test.push(222);
	std::cout << test.pop() << std::endl
		<< test.pop() << std::endl;
	test.push(222);
	test.push(222);
	test.push(222);
	return 0;
}
