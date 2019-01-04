#include <iostream>

template<typename T>
class List
{
	struct Node
	{
		T value;
		Node * next;
		Node * prev;
	};
	int size;
	Node * head;
	Node * tail;
public:
	List()
	{
		size = 0;
		head = tail = NULL;
	}
	List(const List & list)
	{
		size = 0;
		head = tail = NULL;
		Node * point = list.tail;
		while(point)
		{
			push_back(point->value);
			point = point->prev;
		}
	}
	void push_back(T value)
	{
		size++;
		Node * tmpNode = tail;
		tail = new Node;
		tail->value = value;
		tail->prev = tmpNode;
		if(size > 1)
		{
			tmpNode->next = tail;
		} 
		else
		{
			head = tail;
		}
	}
	~List()
	{
		while(tail != head)
		{
			Node *tmpNode = tail->prev;
			delete tail;
			tail = tmpNode;
		}
		delete tail;
		head = tail = NULL;
	}
};

