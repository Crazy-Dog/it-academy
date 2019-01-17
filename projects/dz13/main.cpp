#include "library.hpp"

int getCommandId(std::string command)
{
	if(command == "1" || 
		command == "add book" || 
		command == "Add book")
	{
		return 1;
	}
	else if(command == "2" || 
		command == "add reader" || 
		command == "Add reader")
	{
		return 2;
	}
	else if(command == "3" || 
		command == "print books" || 
		command == "Print books")
	{
		return 3;
	}
	else if(command == "4" || 
		command == "print readers" || 
		command == "Print readers")
	{
		return 4;
	} 
	else if(command == "exit" || command == "Exit" ||
		command == "e" || command == "E")
	{
		return 0;
	}
	return -1;
}

void menu(int mode)
{
	if(!mode)
	{
		std::cout << "1. Add book" << std::endl
			<< "2. Add reader" << std::endl
			<< "3. Print books" << std::endl
			<< "4. Print readers" << std::endl
			<< "5. Add book" << std::endl
			<< "6. Add book" << std::endl
			<< "7. Add book" << std::endl
			<< "6. Add book" << std::endl << std::endl;
			std::cout << "Note: enter number of item or write in words" << std::endl;
			std::cout << "Selected item (or enter \"e\" to exit): ";
	}
	if(mode == 1)
	{
		system("cls");
		std::cout << "Enter name: " << std::endl << std::endl;
	}
}

int main()
{
	Library library;
	std::string str = "";
	
	while(1)
	{
		menu(0);
		std::cin >> str;
		int commandId = getCommandId(str);
		if(!commandId) break;
		try
		{
			library.processCommand(commandId);
			if(commandId == 1 || commandId == 2)
			{
				while(1)
				{
					menu(1);
					std::cin >> str;
					if(str.length() >= 3 && str.length() <=50)
					{
						library.callFunc(str);
						break;
					}
					else
					{
						throw MyException("Invalid name!!!");
					}
				}
			}
			system("cls");
		}catch(MyException &ex)
		{
			system("cls");
			std::cout << ex.what() << std::endl << std::endl;
		}
		std::cin.clear();
	}
	
	return 0;
}
