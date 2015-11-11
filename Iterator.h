#pragma once
#include "Node.h"
/************************************************************************
*Class: Node
*
*Data Members:
*	Node<a_type>*m_node
*		node pointer that points at the current node for the iterator
*
*Constructors:
*	Iterator()
*		default constructor
*
*	Iterator(Node<a_type> x)
*		takes a node and creates an iterator pointing at it
*
*	Iterator(const Iterator& obj)
*		copy constructor
*		deep copies the passed in iterator
*
*	~LinkedList()
*		empty destructor. there is no memory allocated so nothing to destroy.
*
*
*Mutators:
*	Node<a_type>* get_m_node()const
*		returns m_node
*
*	void set_m_node(Node<a_type>*x)
*	sets m_node to the passed in node
*
*	Iterator<a_type>& operator=(Iterator<a_type>& obj);
*		assignment operator
*		points m_node to the passed in iterators m_node
*
*	Iterator<a_type>& operator++();
*		pre increment operator
*		increments m_node and returns this
*
*	Iterator<a_type> operator++(int in)
*		postt increment operator
*		creates a dummy iterator, increments m_node then returns the dummy iterator
*
*	Iterator<a_type>& operator--();
*		pre decrement operator
*		decrements m_node and returns this
*
*	Iterator<a_type> operator--(int in)
*		post decrement operator
*		creates a dummy iterator, decrements m_node then returns the dummy iterator
*Methods:
*
*
*
*************************************************************************/
template<typename a_type>
class Iterator
{
private:
	Node<a_type>* m_node;
public:
	Iterator();
	Iterator(Node<a_type>* x);
	Iterator(const Iterator& obj);
	~Iterator();
	Node<a_type>* get_m_node()const;
	void set_m_node(Node<a_type>*x);
	Iterator<a_type>& operator=(Iterator<a_type>& obj);
	Iterator<a_type>& operator++();
	Iterator<a_type> operator++(int in);
	Iterator<a_type>& operator--();
	Iterator<a_type> operator--(int in);


};
#include "Iterator.cpp"
