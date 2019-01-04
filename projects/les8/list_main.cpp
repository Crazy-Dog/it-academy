#include "list.hpp"

int main()
{
	List<int> test1;
	test1.push_back(32);
	List<int> test2 = test1;
	std::cout << "hey" << std::endl;
	return 0;
}
