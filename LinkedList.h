#pragma once
#include "Node.h"
#include "Iterator.h"
#include "Exception.h"

/************************************************************************
*Class: LinkedList
*
*Data Members:
*	Node<a_type>*m_head
*		node pointer that points at the first node in the list
*
*	Node<a_type>*m_tail
*		node pointer that points at the last node in the list
*
*Constructors:
*	LinkedList()
*		default constructor
*
*	LinkedList(a_type in_data)
*		takes data and creates a linked list of one with it
*
*	LinkedList(const LinkedList& obj)
*		copy constructor
*		deep copies the passed in linked list
*
*	~LinkedList()
*		calls purge to delete the whole list
*
*
*Mutators:
*	Node<a_type>* get_m_head()const
*		returns m_head;
*		can be used with copy constructor
*
*	Node<a_type>* get_m_tail()const
*		returns m_tail;
*		can be used with copy constructor
*
*	const Node<a_type>& First()
*		returns m_head
*
*	const Node<a_type>& Last()
*		rturn m_tail
*
*	LinkedList& operator=(LinkedList& obj)
*		operator overload =
*
*
*
*
*Methods:
*	bool isEmpty()const
*		checks to make sure the list is not empty
*
*	void Prepend(a_type* in)
*		creates a new node with data at in and places it at the start of the list
*
*	void Append(a_type* in)
*		creates a new node with data at in and places it at the end of the list
*
*	void Purge()
*		deletes the list starting at the end and works it's way to the top
*
*	Node<a_type>& Extract(a_type in)
*		walks through the list and finds the node with the same data and pulls it out of the list
*
*	void InsertAfter(a_type data, a_type* in);
*		finds the node with matching data then creates a new node with the new data and places it after the matched node
*
*	void InsertBefore(a_type data, a_type* in)
*		finds the node with matching data then creates a new node with the new data and places it before the match node
*
*	Node<a_type>* Remove_Head()
*		removes the node at m_head and returns it.
*
*	Iterator<a_type> Begin()
*		creates a new iterator at the start of the list and returns it
*
*	Iterator<a_type> End()
*		creates a new iterator at the end of the list and returns it
*
*
*************************************************************************/
template<typename a_type>
class LinkedList
{
private:
	Node<a_type>* m_tail;
	Node<a_type>* m_head;
	int size;
public:
	LinkedList();
	LinkedList(a_type in_data);
	LinkedList(const LinkedList& obj);
	~LinkedList();
	bool isEmpty()const;
	const Node<a_type>& First();
	const Node<a_type>& Last();
	void Prepend(a_type* in);
	void Append(a_type* in);
	void Purge();
	Node<a_type>& Extract(a_type in);
	void InsertAfter(a_type data, a_type* in);
	void InsertBefore(a_type data, a_type* in);
	Node<a_type>* Remove_Head();
	Iterator<a_type> Begin();
	Iterator<a_type> End();
	Node<a_type>* get_m_head()const;
	Node<a_type>* get_m_tail()const;
};

#include "LinkedList.cpp"