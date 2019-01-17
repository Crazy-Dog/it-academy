#include <iostream>
#include <memory>
#include <algorithm>

#include "reader.hpp"
#include "m_exceptions.hpp"

class Library
{
	std::vector<Reader> readers;						//consider all
	std::vector<Book> books;							//consider availlable books
	void (Library::*f)(std::string); 					//pointer on function without return
	std::vector<Book> (Library::*getBooksPointer)(); 	//pointer on function that returns books
	std::vector<Reader> (Library::*getReadersPointer)();//pointer on function that returns readers
	
	//function that add books to library
	void addBook(std::string name) 
	{
		books.push_back(Book(name));
	}
	//function that add readers to library
	void addReader(std::string name)
	{
		readers.push_back(Reader(name));
	}
	//function that returns books
	void printBooks(std::vector<Book> booksToShow)
	{
		system("cls");
		for(unsigned i = 0; i < booksToShow.size(); i++)
		{
			std::cout << i+1 << ". " << booksToShow.at(i).getName() << std::endl;
		} 
	}
	//function that returns readers
	void printReaders()
	{
		system("cls");
		for(unsigned i = 0; i < readers.size(); i++)
		{
			std::cout << i+1 << ". " << readers.at(i).getName() << std::endl;
		} 
	}
public:
	
	Library()
	{
		f = NULL;
		getBooksPointer = NULL;
		getReadersPointer = NULL;
	}
	void processCommand(int commandId)
	{
		switch(commandId)
		{
			case 1:
				f = &Library::addBook;
				break;
			case 2:
				f = &Library::addReader;
				break;
			case 3:
				printBooks(books);
				system("pause");
				break;
			case 4:
				printReaders();
				system("pause");
				break;
			default:
				throw MyException("Invalid command!!!");
		}
	}
	void callFunc(std::string command)
	{
		if(f != NULL) 
		{
			(*this.*f)(command);
			f = NULL;
		}
		if(getBooksPointer != NULL) 
		{
			(*this.*getBooksPointer)();
			getBooksPointer = NULL;
		}
		if(getReadersPointer != NULL) 
		{
			(*this.*getReadersPointer)();
			getReadersPointer = NULL;
		}
	}
	~Library()
	{
		readers.clear();
		books.clear();
	}
};
