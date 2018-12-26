#include <iostream>

using namespace std;

int main()
{
	//1 task
	int a = 0;
	cin >> a;
	
	if(a<=0)
	{
		cout << "negative" << endl;
	} else 
	{
		cout << "positive" << endl;
	}
	
	//2 task
	if(a%2 == 0)
	{
		cout << "even" << endl;
	} else
	{ 
		cout << "odd" << endl;
	}
	
	//3 task
	if(a*a < 100 || a*a >= 10000)
	{
		cout << "non-two-digit" << endl;
	} else
	{ 
		cout << "two-digit" << endl;
	}
	
	//4 task
	if(a < -100 || a > 100)
	{
		cout << "out" << endl;
	} else
	{ 
		cout << "in" << endl;
	}
	
	//5 task
	if(a%3 == 0 && a%5 == 0)
	{
		cout << "multiply of 3 and 5" << endl;
	} else
	{ 
		cout << "not multiply of 3 and 5" << endl;
	}
	
	//6 task
	if(a%2 == 0 || a%7 == 0)
	{
		cout << "multiply of 2 or 7" << endl;
	} else
	{ 
		cout << "not multiply of 2 or 7" << endl;
	}
	
	//7 task
	cout << -a << endl;
	
	//8 task
	if(a > 1000)
	{
		cout << a/10 << endl;
	} 
	
	//9 task
	if(a%10 == 3)
	{
		cout << (a+1)/2 << endl;
	} 
	
	//10 task
	if(a > 100)
	{
		string tmp = to_string(a);
		tmp[tmp.length() - 2] = '8';
		a = stoi(tmp);
		cout << a << endl;
	} 
	
	return 0;
}
