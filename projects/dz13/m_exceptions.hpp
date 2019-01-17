#include <memory>

class MyException
{
	std::string msg; 
public:
	MyException(std::string msg)
	{
		this->msg = msg;
	}
	std::string what()
	{
		return msg;
	}
};
