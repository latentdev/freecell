#include "LinkedList.h"

/******************************************************
*   Purpose:  default constructor

*         Entry:  none

*         Exit: creates a new empty node for m_head. sets the tail at the head
*******************************************************/
template<typename a_type>
LinkedList<a_type>::LinkedList()
{
	m_head = new Node<a_type>();
	m_tail = m_head;
	size = 0;
}

/******************************************************
*   Purpose:  constructor

*         Entry:  passed in data

*         Exit: creates a new node with the passed in data. sets the tail at the head
*******************************************************/
template<typename a_type>
LinkedList<a_type>::LinkedList(a_type in_data)
{
	m_head = new Node<a_type>(in_data);
	m_tail = m_head;
	size = 1;
}

/******************************************************
*   Purpose:  copy constructor

*         Entry:  passed in const refrence

*         Exit: creates a new Linked List then goes through it creating and copying each node from the passed in const refrence
*******************************************************/
template<typename a_type>
LinkedList<a_type>::LinkedList(const LinkedList & obj)
{
	
	if (obj.isEmpty() != true)
	{
		m_head = new Node<a_type>(obj.get_m_head()->get_m_data());
		for (Node<a_type>* p1 = obj.get_m_head(), *p2 = m_head; p1->get_m_next()!=0; p1 = p1->get_m_next(), p2 = p2->get_m_next())
		{
			p2->set_m_next(new Node<a_type>(p1->get_m_next()->get_m_data(),0,p2));
				m_tail = p2->get_m_next();
		}
		size = obj.size;

	}
}

/******************************************************
*   Purpose:  destructor

*         Entry:  none

*         Exit: calls purge to delete all the memory stored in the nodes
*******************************************************/
template<typename a_type>
LinkedList<a_type>::~LinkedList()
{
	Purge();
}

/******************************************************
*   Purpose:  checks the list to see if it's empty

*         Entry:  none

*         Exit: checks if there is nothing at the head. if so returns true else returns false
*******************************************************/
template<typename a_type>
bool LinkedList<a_type>::isEmpty()const
{
	if (m_head == 0)
		return true;
	else
		return false;
}

/******************************************************
*   Purpose:  getter for m_head

*         Entry:  none

*         Exit: returns a reference to the head
*******************************************************/
template<typename a_type>
const Node<a_type>& LinkedList<a_type>::First()
{
	return m_head;
}

/******************************************************
*   Purpose:  getter for m_tail

*         Entry:  none

*         Exit: returns a reference to the tail
*******************************************************/
template<typename a_type>
const Node<a_type>& LinkedList<a_type>::Last()
{
	return m_tail;
}

/******************************************************
*   Purpose:  create a new node and stick it at the start of the list

*         Entry:  passed in data pointer

*         Exit: creates a new node with the passed in data
				sets the new nodes next to the head and the previous to 0
				then sets the heads previous to the new node
				then points head at new node
*******************************************************/
template<typename a_type>
void LinkedList<a_type>::Prepend(a_type * in)
{
	Node<a_type>* x = new Node<a_type>(*in,m_head,0);
	m_head->set_m_prev(x);
	m_head = x;
}

/******************************************************
*   Purpose:  create a new node and stick it at the end of the list

*         Entry:  passed in data pointer

*         Exit: creates a new node with the passed in data
				sets the new nodes next to 0 and the previous to the tail
				then sets the tails next to the new node
				then points tail at new node
*******************************************************/
template<typename a_type>
void LinkedList<a_type>::Append(a_type * in)
{
	Node<a_type>* x = new Node<a_type>(*in,0,m_tail);
	m_head->set_m_next(x);
	m_tail = x;
}

/******************************************************
*   Purpose:  delete all nodes in list

*         Entry:  none

*         Exit: starts at the end of the list deletes the node then moves on to the previous till there are no nodes left
*******************************************************/
template<typename a_type>
void LinkedList<a_type>::Purge()
{
	Node<a_type>* point = m_tail;
	Node<a_type>* temp = point->get_m_prev();
	while (temp != 0)
	{
		temp = point->get_m_prev();
		delete point;
		point = temp;
	}
	m_head = 0;
	m_tail = 0;
}

/******************************************************
*   Purpose:  find a specific node and pull it out of the list

*         Entry:  passed in data

*         Exit: walks through list till it finds the data then sets the previous and next node to each other and returns the found node
*******************************************************/
template<typename a_type>
Node<a_type>& LinkedList<a_type>::Extract(a_type in)
{
	Node<a_type>*point = m_head;
	if (isEmpty() == true)
	{
		throw Exception("List is empty");
		//Node<a_type> x = 0;
		return nullptr;
	}
	
	else if (m_head->get_m_data() == in)
	{
		point = m_head;
		m_head->get_m_next()->set_m_prev(0);
		m_head = m_head->get_m_next();
		return *point;
	}
	Node<a_type>*temp = m_head->get_m_prev();
	while (point != 0 && point->get_m_data() != in)
	{
		temp = point;
		point = point->get_m_next();
	}

	if (point == 0)
		throw Exception("Node not found");
	else
	{
		if (point->get_m_next() != 0)
		{
			point->get_m_prev()->set_m_next(point->get_m_next());
			point->get_m_next()->set_m_prev(point->get_m_prev());
			return *point;
		}
		else
		{
			m_tail = point->get_m_prev();
			m_tail->set_m_next(0);
			return *point;
		}

	}
		
}

/******************************************************
*   Purpose:  create a new node and sticks it after a certain node

*         Entry:  passed in data pointer and the passed in data for compare

*         Exit: walks through list comparing data then creates a new node with the new data and places it after the found node
*******************************************************/
template<typename a_type>
void LinkedList<a_type>::InsertAfter(a_type data, a_type * in)
{
	Node<a_type>* point = m_head;
	while (point != 0 && point->get_m_data() != data)
		point = point->get_m_next();
	if (point != 0)
	{
		if (point->get_m_next() != 0)
		{
			Node<a_type>* x = new Node<a_type>(*in, point->get_m_next(), point);
			point->get_m_next()->set_m_prev(x);
			point->set_m_next(x);
		}
		else
		{
			Node<a_type>* x = new Node<a_type>(*in, 0, point);
			point->set_m_next(x);
		}
			
		
	}
	else throw Exception("Node does not exist");

}

/******************************************************
*   Purpose:  create a new node and sticks it before a certain node

*         Entry:  passed in data pointer and the passed in data for compare

*         Exit: walks through list comparing data then creates a new node with the new data and places it before the found node
*******************************************************/
template<typename a_type>
void LinkedList<a_type>::InsertBefore(a_type data, a_type * in)
{
	if (m_head == 0)
		throw Exception("List is empty");
	else if (m_head->get_m_data() == data)
	{
		Node<a_type>* x = new Node<a_type>(*in, m_head->get_m_next(), m_head);
		m_head->get_m_next()->set_m_prev(x);
		m_head->set_m_next(x);
	}
	else
	{
		Node<a_type>* point = m_head;
		Node<a_type>* prev = 0;
		while (point != 0 && point->get_m_data() != data)
		{
			prev = point;
			point = point->get_m_next();
		}
		if (point != 0 && point->get_m_next() != 0)
		{
			Node<a_type>* x = new Node<a_type>(*in, point, prev);
			prev->set_m_next(x);
			point->set_m_prev(x);
		}
		else
			throw Exception("Node does not exist");

	}
}

template<typename a_type>
Node<a_type>* LinkedList<a_type>::Remove_Head()
{
	if (isEmpty() == true)
		return nullptr;
	else
	{
		Node<a_type>* temp = m_head;
		m_head->get_m_next()->set_m_prev(0);
		m_head = m_head->get_m_next();
		return temp;
	}
}

/******************************************************
*   Purpose:  create a new iterator at the start of the list

*         Entry:  none

*         Exit: creates a new iterator that is pointing at the head and returns it
*******************************************************/
template<typename a_type>
Iterator<a_type> LinkedList<a_type>::Begin()
{
	return *(new Iterator<a_type> (m_head));
}

/******************************************************
*   Purpose:  create a new iterator at the end of the list

*         Entry:  none

*         Exit: creates a new iterator that is pointing at the tail and returns it
*******************************************************/
template<typename a_type>
Iterator<a_type> LinkedList<a_type>::End()
{
	return *(new Iterator<a_type>(m_tail));
}

/******************************************************
*   Purpose:  getter for m_head

*         Entry:  const for copy constructor

*         Exit: returns m,_head
*******************************************************/
template<typename a_type>
Node<a_type>* LinkedList<a_type>::get_m_head()const
{
	return m_head;
}

/******************************************************
*   Purpose:  getter for m_tail

*         Entry:  const for copy constructor

*         Exit: returns m,_tail
*******************************************************/
template<typename a_type>
Node<a_type>* LinkedList<a_type>::get_m_tail()const
{
	return m_tail;
}
