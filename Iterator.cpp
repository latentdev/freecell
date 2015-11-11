#include "Iterator.h"

/******************************************************
*   Purpose:  default constructor for iterator

*         Entry:  none

*         Exit: sets m_node to 0
*******************************************************/
template<typename a_type>
Iterator<a_type>::Iterator()
{
	m_node = 0;
}

/******************************************************
*   Purpose:  constructor for iterator

*         Entry:  passed in a pointer to a node

*         Exit: sets m_node to the passed in x
*******************************************************/
template<typename a_type>
Iterator<a_type>::Iterator(Node<a_type>* x)
{
	m_node = x;
}

/******************************************************
*   Purpose:  copy constructor for iterator

*         Entry:  passed in a const refrence to an iterator

*         Exit: sets m_node to the passed in obj' m_node
*******************************************************/
template<typename a_type>
Iterator<a_type>::Iterator(const Iterator & obj)
{
	m_node = obj.get_m_node();
}

/******************************************************
*   Purpose:  destructor for iterator

*         Entry:  none

*         Exit: does nothing because there is no memory stored in iterator
*******************************************************/
template<typename a_type>
Iterator<a_type>::~Iterator()
{
}

/******************************************************
*   Purpose:  getter for m_node

*         Entry:  none

*         Exit: returns m_node
*******************************************************/
template<typename a_type>
Node<a_type>* Iterator<a_type>::get_m_node()const
{
	return m_node;
}

/******************************************************
*   Purpose:  setter for m_node

*         Entry: passed in a pointer to a node

*         Exit: sets m_node to the passed in node
*******************************************************/
template<typename a_type>
void Iterator<a_type>::set_m_node(Node<a_type>* x)
{
	m_node = x;
}

/******************************************************
*   Purpose:  overloaded assignment operator

*         Entry:  passed in a reference to an iterator

*         Exit: sets m_node to the passed in iterator's m_node. returns this.
*******************************************************/
template<typename a_type>
Iterator<a_type>& Iterator<a_type>::operator=(Iterator<a_type>& obj)
{
	m_node = *obj.get_m_node();
	return *this;
}

/******************************************************
*   Purpose:  prefix increment operator

*         Entry:  none

*         Exit: check to make sure we are not at the end of the list then set m_node to the next node and return this
*******************************************************/
template<typename a_type>
Iterator<a_type>& Iterator<a_type>::operator++()
{
	//cout << m_node->get_m_next()<<endl;
	if (m_node->get_m_next()!=0)
	m_node = m_node->get_m_next();
	else throw Exception("End of list");
	return *this;
}

/******************************************************
*   Purpose:  postfix increment operator

*         Entry:  dummy int to define postfix

*         Exit: create new iteretor at current point in list increment this return the new iterator
*******************************************************/
template<typename a_type>
Iterator<a_type> Iterator<a_type>::operator++(int in)
{
	//Node<a_type>* point = m_node;
	Iterator<a_type> * x= new Iterator<a_type>(this->get_m_node());
	++(*this);
	return *x;
}

/******************************************************
*   Purpose:  prefix decrement operator

*         Entry:  none

*         Exit: check to make sure we are not at the start of the list then set m_node to the previous node and return this
*******************************************************/
template<typename a_type>
Iterator<a_type>& Iterator<a_type>::operator--()
{
	if (m_node->get_m_prev() != 0)
		m_node = m_node->get_m_prev();
	else throw Exception("End of list");
	return *this;
}

/******************************************************
*   Purpose:  postfix decrement operator

*         Entry:  dummy int to define postfix

*         Exit: create new iteretor at current point in list decrement this return the new iterator
*******************************************************/
template<typename a_type>
Iterator<a_type> Iterator<a_type>::operator--(int in)
{
	Iterator<a_type> * x = new Iterator<a_type>(this->get_m_node());
	--(*this);
	return *x;
}
