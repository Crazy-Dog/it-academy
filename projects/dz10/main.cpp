#include <iostream>
#include <fstream>

int main()
{
	std::fstream file("str.txt", std::ios::in | std::ios::out);
	int currPos = 0, flag = 1;

	while (flag)
	{
		file.seekg(currPos);
		int tmpVal = 0;
		file >> tmpVal;
		if (file.eof()) flag = 0;
		int pos = currPos;
		currPos += 5;

		for (int j = pos - 5; j >= 0; j = j - 5)
		{
			int test;
			file.seekg(j);
			file >> test;
			if (tmpVal < test) break;
			file.seekp(j + 5);
			file << test;
			pos = j;
		}
		file.seekp(pos);
		file << tmpVal;
	}

	file.close();

	return 0;
}
