#include <iostream>

template<typename T>
class Stack {
	class Node
	{
	public:
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
		T tmpValue = {};
		if(top != NULL)
		{
			tmpValue = top->value;
			if(top->prev != NULL)
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
		return tmpValue;
	}
	~Stack() 
	{
		while(top != NULL)
		{
			if(top->prev != NULL)
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
