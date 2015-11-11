#pragma once
/************************************************************************
*Class: Node
*
*Data Members:
*	a_type m_data
*		holds data
*
*	Node<a_type>*m_next
*		node pointer that points at the next node
*
*	Node<a_type>*m_prev
*		node pointer that points at the previous node
*
*Constructors:
*	Node()
*		default constructor
*
*	Node(a_type in_data)
*		takes data and creates a node with it
*
*	Node(a_type in_data, Node * in_next, Node * in_prev)
*		takes data and addresses for the next and previous node and creates a node
*
*	Node(const Node& obj)
*		copy constructor
*		deep copies the passed in node
*
*	~LinkedList()
*		checks to make sure it's not at the start or end of the list then sets the previous and next nodes to each other and deletes the node
*		if it is at the start or end then it sets the appropriate pointers to 0 and deletes itself
*
*
*Mutators:
*	a_type get_m_data()const
*		returns m_data
*
*	void set_m_data(a_type in_data);
*		sets m_data to the passed in value
*
*	Node<a_type>* get_m_next()const
*		returns m_next
*
*	void set_m_next(Node<a_type>* in_next)
*		sets m_next to the passed in value
*
*	Node<a_type>* get_m_prev()const
*		returns m_prev
*
*	void set_m_prev(Node* in_prev)
*		sets m_prev to the passed in value
*
*Methods:
*	
*
*
*************************************************************************/
template <typename a_type>
class Node
{
private:
	a_type m_data;
	Node<a_type>* m_next;
	Node<a_type>* m_prev;
public:
	Node();
	Node(a_type in_data);
	Node(a_type in_data, Node * in_next, Node * in_prev);
	Node(const Node& obj);
	~Node();
	a_type get_m_data()const;
	void set_m_data(a_type in_data);
	Node<a_type>* get_m_next()const;
	void set_m_next(Node<a_type>* in_next);
	Node<a_type>* get_m_prev()const;
	void set_m_prev(Node* in_prev);

};
#include "Node.cpp"