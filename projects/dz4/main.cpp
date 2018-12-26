#include <iostream>
#include <ctime>
#include "proto.hpp"

int main()
{
	const int SIZE = 20;
	srand( time( 0 ) );
	int arr[SIZE];
	for(int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 100;
	}
	
	my_sort(arr, SIZE);
	
	for(int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << " ";
	}
	
	return 0;
}
