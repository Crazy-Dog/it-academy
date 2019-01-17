#pragma once
#include <vector>

#include "books.hpp"

class Reader
{
	std::string name;
	std::vector<Book> books;
public:
	Reader()
	{
		name = "none";
	}
	Reader(std::string name)
	{
		this->name = name;
	}
	void addBook(Book book)
	{
		books.push_back(book);
	}
	std::string getName()
	{
		return name;
	}
	std::vector<Book> getBooks()
	{
		return books;
	}
	bool operator <(const Reader & reader)
	{
		return (this->name < reader.name);
	}
	bool operator ==(const Reader & reader)
	{
		return (this->name == reader.name);
	}
	~Reader()
	{
		name.clear();
		books.clear();
	}
};
