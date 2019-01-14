#include <iostream>
#include <list>
#include <ctime>
#include "m_stack.hpp"

class TicTacToe
{
	int mode;
	bool x_or_0;
	int steps[9];
	int isEnded;
	void pl1_move(int x, int y)
	{
		steps[y*3 + x] = (x_or_0 ? 1 : 0);
	}
	void pl2_move(int x, int y)
	{
		steps[y*3 + x] = (!x_or_0 ? 1 : 0);
	}
	void redraw()
	{
		system("cls");
		std::cout << " --- --- ---" << std::endl;
		for(int i = 0; i < 9; i = i + 3)
		{
			std::cout << "| " << getXOChar(steps[i]) << " | ";
			std::cout << getXOChar(steps[i+1]) << " | ";
			std::cout << getXOChar(steps[i+2]) << " |" << std::endl;
			std::cout << " --- --- ---" << std::endl;
		}
	}
	char getXOChar(int key)
	{
		char tmpXOChar;
		switch(key)
		{
			case 0:
				tmpXOChar = 'O';
				break;
			case 1:
				tmpXOChar = 'X';
				break;
			default:
				tmpXOChar = ' ';
		}
		return tmpXOChar;
	}
	void computeMove(int & coord_x, int & coord_y)
	{
		srand(time(0));
		int tmpIndex = rand() % 9;
		int noFreeMoves = 0;
		while(steps[tmpIndex] != -1)
		{
			srand(time(0));
			tmpIndex = rand() % 9;
			for(int i = 0; i < 9; i++)
			{
				if(steps[i] != -1) 
				{
					noFreeMoves = 1;
				}
			}
			if(!noFreeMoves) return;
		}
		steps[tmpIndex] = !x_or_0;
	}
	void checkEnd()
	{
		int isMovesEnded = 0;
		for(int i = 0; i < 9; i=i+3)
		{
			if(steps[i] == steps[i+1] && steps[i+1] == steps[i+2] && steps[i] != -1)
			{
				isMovesEnded = 1;
			}
		}
		isEnded = isMovesEnded;
		std::cout << isEnded << std::endl;
		if(isEnded)return;
		for(int i = 0; i < 3; i++)
		{
			if(steps[i] == steps[i+3] && steps[i+3] == steps[i+6] && steps[i] != -1)
			{
				isMovesEnded = 1;
			}
		}
		isEnded = isMovesEnded;
		std::cout << isEnded << std::endl;
		if(isEnded)return;
		if(steps[2] == steps[4] && steps[4] == steps[6] && steps[2] != -1)
		{
			isMovesEnded = 1;
		}
		isEnded = isMovesEnded;
		std::cout << isEnded << std::endl;
		if(isEnded)return;
		if(steps[0] == steps[4] && steps[4] == steps[8] && steps[0] != -1)
		{
			isMovesEnded = 1;
		}
		isEnded = isMovesEnded;
		std::cout << isEnded << std::endl;
		if(isEnded)return;
		isMovesEnded = 1;
		for(int i = 0; i < 9; i++)
		{
			if(steps[i] != -1) 
			{
				isMovesEnded = 0;
			}
		}
		isEnded = isMovesEnded;
		std::cout << isEnded << std::endl;
	}
public:
	TicTacToe(int mode = 0, int x_or_0 = 0)
	{
		this->mode = (mode ? 1 : 0);
		this->x_or_0 = (x_or_0 ? 1 : 0);
		isEnded = 0;
		for(int i = 0; i < 9; i++)
		{
			steps[i] = -1;
		}
	}
	void run()
	{
		int coord_x = 0;
		int coord_y = 0;
		while(coord_x < 1 || coord_x > 3 || coord_y < 1 || coord_y > 3)
		{
			std::cout << "1 player turn, ender coordinates. X(from 1 to 3): ";
			std::cin >> coord_x;
			std::cout << "Y(from 1 to 3): ";
			std::cin >> coord_y;
		}
		pl1_move(--coord_x, --coord_y);
		coord_x = 0;
		coord_y = 0;
		if(mode)
		{
			while(coord_x < 1 || coord_x > 3 || coord_y < 1 || coord_y > 3)
			{
				std::cout << "2 player turn, ender coordinates. X(from 1 to 3): ";
				std::cin >> coord_x;
				std::cout << "Y(from 1 to 3): ";
				std::cin >> coord_y;
			}
		} 
		else
		{
			computeMove(coord_x, coord_y);
		}
		pl2_move(--coord_x, --coord_y);
		redraw();
		checkEnd();
	}
	int gameEnded()
	{
		return isEnded;
	}
	~TicTacToe()
	{
	}
};
