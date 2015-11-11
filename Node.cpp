#include "Node.h"

/******************************************************
*   Purpose:  default constructor

*         Entry:  none

*         Exit: sets all data members to zero
*******************************************************/
template<typename a_type>
Node<a_type>::Node()
{
	m_data = 0;
	m_next = 0;
	m_prev = 0;
}

/******************************************************
*   Purpose:  constructor

*         Entry:  passed in data

*         Exit: sets m_data to the passed in data and sets the other data members to zero
*******************************************************/
template<typename a_type>
Node<a_type>::Node(a_type in_data)
{
	m_data = in_data;
	m_next = 0;
	m_prev = 0;
}

/******************************************************
*   Purpose:  constructor

*         Entry:  passed in data, a pointer to the next node and a pointer to the previous node

*         Exit: sets m_node to the passed in data, sets m_next to the next node and m_previous to the previous node
*******************************************************/
template<typename a_type>
Node<a_type>::Node(a_type in_data, Node * in_next, Node * in_prev)
{
	m_data = in_data;
	m_next = in_next;
	m_prev = in_prev;
}

/******************************************************
*   Purpose:  copy constructor

*         Entry:  passed a const Node refrence

*         Exit: sets all data members to obj's data members
*******************************************************/
template<typename a_type>
Node<a_type>::Node(const Node & obj)
{
	m_data = obj.get_m_data();
	m_next = obj.get_m_next();
	m_prev = obj.get_m_prev();
}

/******************************************************
*   Purpose:  destructor

*         Entry:  none

*         Exit: checks to see if its in the middle of the list then sets the previous nodes next to the next node
				and the next nodes previous to the previous node then deletes itself.
				if it's at the tail we set the previous nodes next to 0 and delete itself.
				if it's at the head we set the next nodes previous to 0 and delete itself.
*******************************************************/
template<typename a_type>
Node<a_type>::~Node()
{
	if (m_next != 0 && m_prev != 0)
	{
		m_prev->m_next = m_next;
		m_next->m_prev = m_prev;
	}

	else if (m_next == 0 && m_prev != 0)
		m_prev->m_next = 0;

	else if (m_prev == 0 && m_next != 0)
		m_next->m_prev = 0;
}

/******************************************************
*   Purpose:  getter for m_data

*         Entry:  none

*         Exit: returns m_data
*******************************************************/
template<typename a_type>
a_type Node<a_type>::get_m_data()const
{
	return m_data;
}

/******************************************************
*   Purpose:  setter for m_data

*         Entry:  passed in data

*         Exit: sets m_data to passed in data
*******************************************************/
template<typename a_type>
void Node<a_type>::set_m_data(a_type in_data)
{
	m_data = in_data;
}

/******************************************************
*   Purpose:  getter for m_next

*         Entry:  none

*         Exit: returns m_next
*******************************************************/
template<typename a_type>
Node<a_type>* Node<a_type>::get_m_next()const
{
	return m_next;
}

/******************************************************
*   Purpose:  setter for m_next

*         Entry:  passed in node pointer

*         Exit: sets m_next to passed in node pointer
*******************************************************/
template<typename a_type>
void Node<a_type>::set_m_next(Node<a_type>* in_next)
{
	m_next = in_next;
}

/******************************************************
*   Purpose:  getter for m_prev

*         Entry:  none

*         Exit: returns m_prev
*******************************************************/
template<typename a_type>
Node<a_type>* Node<a_type>::get_m_prev()const
{
	return m_prev;
}

/******************************************************
*   Purpose:  setter for m_prev

*         Entry:  passed in node pointer

*         Exit: sets m_prev to passed in node pointer
*******************************************************/
template<typename a_type>
void Node<a_type>::set_m_prev(Node<a_type>* in_prev)
{
	m_prev = in_prev;
}
