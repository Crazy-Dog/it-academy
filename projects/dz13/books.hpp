#pragma once
#include <string>

class Book
{
	std::string name;
public:
	Book()
	{
		name = "none";
	}
	Book(std::string name)
	{
		this->name = name;
	}
	std::string getName()
	{
		return name;
	}
	~Book()
	{
		name.clear();
	}
};
