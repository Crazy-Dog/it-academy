#include <iostream>
void my_sort(int * arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		int tmpVal = arr[i];
		int pos = i;
		for(int j = i - 1; tmpVal < arr[j] && j >= 0; j--)
		{
			arr[j+1] = arr[j];
			pos = j;
		}
		arr[pos] = tmpVal;
	}
}
