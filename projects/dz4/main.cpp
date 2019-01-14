#include <iostream>
#include <ctime>

int main()
{
	const int SIZE = 20;
	srand( time( 0 ) );
	int arr[SIZE];
	for(int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 3;
	}
	
	for(int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << " ";
	}
	
	return 0;
}
