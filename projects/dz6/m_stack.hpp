#include <iostream>

template<typename T>
class Stack {
	struct Node
	{
		T value;
		Node * prev;
	};
	Node * top;
public:
	Stack()
	{
		top = NULL;
	}
	void push(T value) 
	{
		Node * tmpNode = top;
		top = new Node;
		top->value = value;
		top->prev = tmpNode;
	}
	T pop() 
	{
		T tmpValue(0);
		if(top)
		{
			tmpValue = top->value;
			Node *tmpNode = top->prev;
			delete top;
			top = tmpNode;
		}
		return tmpValue;
	}
	~Stack() 
	{
		while(top)
		{
			if(top->prev)
			{
				Node *tmpNode = top->prev;
				delete top;
				top = tmpNode;
			} 
			else
			{
				delete top;
				top = NULL;
			}
		}
	}
};
