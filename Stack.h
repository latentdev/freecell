#pragma once
#include "LinkedList.h"

/************************************************************************
*Class: LinkedList
*
*Data Members:
*	LinkedList<a_type>*m_list
*		LinkedList pointer that points at out list that is the data container for our stack
*
*	int size
*		max size of our stack
*
*	int fill
*		current number of items on our stack
*
*Constructors:
*	Stack()
*		default constructor
*
*	Stack(int in_size)
*		takes a size and creates a new stack with that size
*
*	Stack(const Stack& obj)
*		copy constructor
*		does a deep copy of the passed in objects m_list
*		sets size to the passed in objects size
*		sets fill to the passed in objects fill
*
*	~Stack()
*		deletes m_list
*
*
*Accessors:
*	LinkedList<a_type>* get_m_list()const
*		returns m_list protected and const for constness' sake
*
*	int get_size()const
*		returns size protected and const for constness' sake
*
*	int get_fill()const
*		returns fill protected and const for constness' sake
*
*	int Size()
*		returns size
*
*Methods:
*	void Push(a_type* in_data)
*		prepends a node containing the passed in data to out m_list
*
*	Node<a_type>* Pop()
*		call remove_head on list to remove the first node in the list and return it
*
*	Node<a_type>* Peek()
*		returns the first node of m_list without removing it;
*
*	bool isEmpty();
*		checks if the stack is empty
*
*	bool isFull();
*		checks if the stack is full
*
*************************************************************************/
template<typename a_type>
class Stack
{
private:
	LinkedList<a_type>* m_list;
	int size;
	int fill;

public:
	Stack();
	Stack(int in_size);
	Stack(const Stack& obj);
	~Stack();
	void Push(a_type* in_data);
	Node<a_type>* Pop();
	Node<a_type>* Peek();
	int Size();
	bool isEmpty();
	bool isFull();

protected:
	LinkedList<a_type>* get_m_list()const;
	int get_size()const;
	int get_fill()const;
};

#include "Stack.cpp"