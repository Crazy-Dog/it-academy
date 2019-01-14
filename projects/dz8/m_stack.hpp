#include <iostream>

template<typename T>
class Stack {
	struct Node
	{
		T value;
		Node * prev;
	};
	Node * top;
	void copy(Node *pb)
	{
		if(!pb) 
		{
			top = NULL;
			return;
		}
		copy(pb->prev);
		push(pb->value);
	}
public:
	Stack()
	{
		top = NULL;
	}
	Stack(const Stack & obj)
	{
		copy(obj.top);
	}
	Stack & operator = (const Stack & obj)
	{
		copy(obj.top);
		return *this;
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
