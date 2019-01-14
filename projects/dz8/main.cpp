#include "game.hpp"

int main()
{
	int playKey;
	while(playKey)
	{
		TicTacToe game;
		while(!game.gameEnded())
		{
			game.run();
		}
		playKey = 2;
		while(playKey == 2)
		{
			char continueSymbol;
			std::cout << "continue?(Y/N): ";
			std::cin >> continueSymbol;
			if(continueSymbol == 'Y' || continueSymbol == 'y')
			{
				playKey = 1;
			} 
			else if(continueSymbol == 'N' || continueSymbol == 'n')
			{
				playKey = 0;
			}
			else 
			{
				playKey = 2;
			}
		}
	}	
	return 0;
}
