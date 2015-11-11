#pragma once
/************************************************************************
*Class: Array
*
*Constructors:
*	Array()
*		fills out the member variables with data for testing purposes
*
*	Array(int length,int start_index);
*		m_length and m_start_index are initialized to length and start_index.
*		create an array for m_array to point at.
*
*	Array(const Array& obj)
*		Takes a reference to an Array class and and copies m_length and m_start_index into the new instance.
*		creates an array for m_array and does a deep copy of obj.m_array.
*
*	~Array()
*		deletes pointer m_array
*
*Mutators:
*	void setLength(int length)
*		takes an integer and sets m_length to it.
*
*	void setStartIndex(int start_index)
*		takes an integer and sets the m_start_index.
*
*	Array& operator=(Array& rhs)
*		operator overload =
*		Pulls m_length and m_start_index and stores them in this instances m_length and m_start_index
*		Frees up current space allocated by m_array and then does a deep copy from rhs.m_array
*
*	a_type& operator[](int index)
*		Tests for out of bounds and throws the appropriate exception
*		If index passes both checks then we return the data stored at index - m_start_index
*		to compensate for a different start index than 0 we subtract m_start_index from index
*
*Methods:
*	int getLength()
*		returns the length of our array.
*
*	int getStartIndex()
*		returns the starting index of our array.
*
*************************************************************************/
template <class a_type> class Array
{
	private:
		a_type *m_array;
		int m_length;
		int m_start_index;
	public:
		Array();
		Array(int length, int start_index);
		Array(const Array& obj);
		~Array();
		Array& operator=(Array& rhs);
		a_type& operator[](int index);
		int getStartIndex()const;
		void setStartIndex(int start_index);
		int getLength()const;
		void setLength(int length);
	
};
#include "Array.cpp"


