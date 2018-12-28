#include "m_stack.hpp"

int main()
{
	Stack<int> test;
	test.push(10);
	test.push(11);
	test.push(4242);
	std::cout << test.pop() << std::endl; 
	Stack<int> test2 = test;
	std::cout << test2.pop() << std::endl;
	std::cout << test2.pop() << std::endl;
	Stack<int> test3;
	test3 = test2 = test;
	std::cout << test3.pop() << std::endl;
	std::cout << test3.pop() << std::endl;
	std::cout << test3.pop() << std::endl;
	std::cout << test2.pop() << std::endl;
	return 0;
}
