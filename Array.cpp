#include "Array.h"
#include "Exception.h"
#include <iostream>

/************************************************************
*Default Constructor. 
*I made it fill out the member variables for testing purposes
*************************************************************/
template<class a_type>
inline Array<a_type>::Array()
{
	//cout << "Invoking default constructor to create an Array object" << endl;
	m_length = 4;
	m_start_index = 0;
	m_array = new a_type[m_length];
	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = i;
	}
}

/*********************************************************************************
*Parameterized Constructor. 
*Takes int length and int start_index and sets m_length and m_start_index to them. 
*Create a new array and set m_array to point at it
**********************************************************************************/
template<class a_type>
inline Array<a_type>::Array(int length, int start_index)
{
	//cout << "Invoking parameterized constructor to create an Array object" << endl;

	m_length = length;
	m_start_index = start_index;
	m_array = new a_type[length];
}

/*********************************************************************************
*Copy Constructor.
*Takes Array class and and copies m_length and m_start_index into the new instance
*creates an array for m_array and does a deep copy of obj.m_array
**********************************************************************************/
template<class a_type>
inline Array<a_type>::Array(const Array & obj)
{
	//cout << "Copy constructor activated!" << endl;

	m_start_index = obj.getStartIndex();
	m_length = obj.getLength();
	m_array = new a_type[m_length];

	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = obj.m_array[i];
	}

}

/*****************
*Destructor.
*Deletes m_array
******************/
template<class a_type>
inline Array<a_type>::~Array()
{
	//cout << "destroying things..." << endl;

	delete m_array;

}

/*********************************************************************************************
*Overloaded = operator.
*Pulls m_length and m_start_index and stores them in this instances m_length and m_start_index
*Frees up current space allocated by m_array and then does a deep copy from rhs.m_array
**********************************************************************************************/
template<class a_type>
Array<a_type>& Array<a_type> ::operator=(Array & rhs)
{
	//cout << "Equals operator is happening!" << endl;

	m_start_index = rhs.getStartIndex();
	m_length = rhs.getLength();
	delete [] m_array;
	m_array = new a_type[m_length];

	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = rhs.m_array[i];
	}

	return *this;
	
}
/*************************************************************************************
*Overloaded [] operator.
*Tests for out of bounds and throws the appropriate exception
*If index passes both checks then we return the data stored at index - m_start_index
*to compensate for a different start index than 0 we subtract m_start_index from index
**************************************************************************************/
template<class a_type>
a_type& Array<a_type> ::operator[](int index)
{
	if (index < m_start_index) {
		throw Exception("Index smaller than lower bounds");
	}

	else if (index >= m_length + m_start_index) {
		throw Exception("Index larger than upper bounds");
	}

	else
	{
		return m_array[index - m_start_index];
	}
	
}
/*************************************************
*Getter for starting index.
*Returns m_start_index
**************************************************/
template<class a_type>
int Array<a_type>::getStartIndex()const
{
	return m_start_index;
}
/*************************************************
*Setter for starting index.
*Sets m_start_index to passed in start_index
**************************************************/
template<class a_type>
void Array<a_type>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

/*************************************************
*Getter for length of array
*returns m_length
**************************************************/
template<class a_type>
int Array<a_type>::getLength()const
{
	return m_length;
}

/*************************************************
*Setter for m_length
*creates a temp pointer a_type and points it at a new array of passed in length
* then checks which is shorter so we only loop as many times as needed
*then fill the temp array with the m_array
* deletes m_array and then points m_array at the temp array
**************************************************/
template<class a_type>
void Array<a_type>::setLength(int length)
{
	int shorter = 0
	a_type* m_array_temp = new a_type[length];

	if (length > m_length)
		shorter = m_length;
	else
		shorter = length;

	for (int i = 0; i < shorter; i++) {
		m_array_temp[i] = m_array[i];
	}

	delete[] m_array;
	m_array = m_array_temp;
}






