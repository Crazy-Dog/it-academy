#include <iostream>
#include <fstream>

int main()
{
	std::fstream file("str.txt", std::ios::in | std::ios::out);
	int currPos = 0;
	
	while(1)
	{
		file.seekg(currPos);
		char buf[4];
		file.read(buf, 4);
		if(file.eof()) break;
		int tmpVal = atoi(buf);
		currPos += 5;
		
//		std::cout << atoi(buf) << ' ';
		
		int pos = currPos;
		for(int j = currPos - 5; j >= 0; j = j - 5)
		{
			char tmpTest[4];
			file.seekg(j);
			file.read(tmpTest, 4);
			int test = atoi(tmpTest);
			if(tmpVal < test)
			{
				pos = j;
				std::cout << test << ' ';
				break;
			}
			file.seekp(j+5);
			file.write(tmpTest, 4);
			pos = j;
		}
		file.seekp(pos);
		file.write(buf, 4);
	}
	
	file.close();
	
	return 0;
}
