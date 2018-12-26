#include <iostream>

template<typename N>
class Node;

template<typename T>
class MyStack
{
	Node<T> * head = NULL;
public:
	void push(T val) 
	{
		if(head != NULL)
		{
			head->next = new Node<T>;
			Node<T> * tmp = head;
			head = head->next;
		
			head->prev = tmp;
			head->val = val;
			head->next = NULL;
		} else 
		{
			head = new Node<T>;
			head->prev = NULL;
			head->val = val;
			head->next = NULL;
		}
	}
	T pop()
	{
		T tmp = NULL;
		if(head != NULL)
		{
			tmp = head->val;
			if(head->prev != NULL)
			{
				Node<T> * tmpNode = head;
				head = head->prev;
				delete tmpNode;
			} else
			{
				delete head;
				head = NULL;
			}
		}
		return tmp;
	}
};

template<typename N>
class Node
{
	friend class MyStack<N>;
	N val;
	Node * next;
	Node * prev;
};

int main()
{
	MyStack<int> test;
	test.push(8);
	test.push(15);
	test.push(-10);
	
	std::cout << test.pop() << std::endl;
	std::cout << test.pop() << std::endl;
	std::cout << test.pop() << std::endl;
	
	return 0;
}
