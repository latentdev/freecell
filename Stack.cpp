//#include "Stack.h"
#include "Node.h"
#include "Stack.h"


/******************************************************
*   Purpose:  default constructor

*         Entry:  none

*         Exit: sets all the member variables to null
*******************************************************/
template<typename a_type>
Stack<a_type>::Stack()
{
	m_list = NULL;
	size = 0;
	fill = 0;
}

/******************************************************
*   Purpose:  constructor

*         Entry:  passed in an int representing size

*         Exit: creates a new empty linkedlist object theat m_list points at.
				sets size to the passed in size.
				sets fill to 0 because there is nothing on the stack
*******************************************************/
template<typename a_type>
Stack<a_type>::Stack(int in_size)
{
	m_list = new LinkedList<a_type>();
	size = in_size;
	fill = 0;
}

/******************************************************
*   Purpose:  copy constructor

*         Entry:  passed in a const refrence to a stack

*         Exit: creates a new linkedlist using the linked list copy constructor passing in the objects linked list
				sets size to the passed in objects size
				sets fill to the passed in objects fill
*******************************************************/
template<typename a_type>
Stack<a_type>::Stack(const Stack& obj)
{
	m_list = new LinkedList<a_type>(*obj.get_m_list());
	size = obj.get_size();
	fill = obj.get_fill();

}

/******************************************************
*   Purpose:  destructor

*         Entry:  none

*         Exit: deletes m_list
*******************************************************/
template<typename a_type>
Stack<a_type>::~Stack()
{
	delete m_list;
}

/******************************************************
*   Purpose:  push an something onto our stack

*         Entry:  passed in the data to store in our list

*         Exit: if the stack is full it throws the stack overflow exception else it calls m_list prepend with the passed in data and increments fill
*******************************************************/
template<typename a_type>
void Stack<a_type>::Push(a_type* in_data)
{
	if (isFull()==true)
		throw Exception("Stack Overflow");
	else
	{
		m_list->Prepend(in_data);
		fill += 1;
	}
}

/******************************************************
*   Purpose:  pop something off our stack

*         Entry:  none

*         Exit: if the stack is empty throws the stack underflow exception else it decrements fill and returns m_list's remove_head function which returns the node that was at m_list's m_head
*******************************************************/
template<typename a_type>
Node<a_type>* Stack<a_type>::Pop()
{
	if (isEmpty() == true)
	{
		throw Exception("Stack Underflow");
		return nullptr;
	}
	else
	{
		fill -= 1;
		return m_list->Remove_Head();	//return m_head node
	}
	
}

/******************************************************
*   Purpose:  look at whats at the top of our stack

*         Entry:  none

*         Exit: returns the node at the start of m_list
*******************************************************/
template<typename a_type>
Node<a_type>* Stack<a_type>::Peek()
{
	return m_list->get_m_head();
}

/******************************************************
*   Purpose:  gets the size of the stack

*         Entry:  none

*         Exit: returns size
*******************************************************/
template<typename a_type>
int Stack<a_type>::Size()
{
	return fill;
}

/******************************************************
*   Purpose:  checks if the stack is empty

*         Entry:  none

*         Exit: calls m_list's isEmpty and if true returns true else returns false
*******************************************************/
template<typename a_type>
bool Stack<a_type>::isEmpty()
{
	if (m_list->isEmpty() == true)
		return true;
	else
		return false;
}

/******************************************************
*   Purpose:  checks if the stack is full

*         Entry:  none

*         Exit: compares the size of the stack and the number of items on the stack.
				if they are equal then return true else return false.
				there should not be a case where fill is greater than size
*******************************************************/
template<typename a_type>
bool Stack<a_type>::isFull()
{
	if (fill == size)
		return true;
	else
		return false;
}

/******************************************************
*   Purpose:  getter for m_list

*         Entry:  none

*         Exit: returns m_list protected and const for constness' sake
*******************************************************/
template<typename a_type>
LinkedList<a_type>* Stack<a_type>::get_m_list()const
{
	return m_list;
}

/******************************************************
*   Purpose:  getter for size

*         Entry:  none

*         Exit: returns size protected and const for constness' sake
*******************************************************/
template<typename a_type>
int Stack<a_type>::get_size()const
{
	return size;
}

/******************************************************
*   Purpose:  getter for fill

*         Entry:  none

*         Exit: returns fill protected and const for constness' sake
*******************************************************/
template<typename a_type>
int Stack<a_type>::get_fill()const
{
	return fill;
}


