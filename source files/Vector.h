#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdexcept>
// Dynamic array (Vector) class
class Vector
{
	// array size
	unsigned int elementNum;
	// pointer to data
	int* pData;

	// global friend operator for printing vector data
	friend std::ostream& operator << (std::ostream& os, const Vector& v);

public:
	// Constructors, destructor
	Vector() { elementNum = 0; pData = NULL; }
	Vector(const Vector& theOther);
	~Vector() { delete[]pData; }

	// returns the array size 
	int  size()const { return elementNum; }

	// clears the array
	void clear();

	// erases (deletes) the array element with the given index;
	// valid indices: from 0 to size-1
	void erase(unsigned int position);

	// returns the array element with the given index, making possible to modify the element;
	// valid indices: between 0 and size()-1
	int& at(unsigned int position);

	// returns the array element with the given index, without possibility to modify the element (see const keyword)
	// valid indices: between 0 and size()-1
	const int& at(unsigned int position)const;

	// inserts a new element into a place with the given index;
	// if the index exceeds the array size, then the size should be increased, and the empty places should be filled with 0 (zero)
	bool insert(unsigned int position, int element);

	// Operator=
	const Vector& operator= (const Vector& theOther);

	// operator[]
	int& operator [](unsigned int position);
	const int& operator [](unsigned int position)const;
};

// global function for printing vector data
std::ostream& operator << (std::ostream& os, const Vector& v);
#endif /*VECTOR_H */
