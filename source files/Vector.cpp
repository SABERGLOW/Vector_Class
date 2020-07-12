#include "Vector.h"


Vector::Vector(const Vector& theOther)//copy constructor
{
    elementNum = theOther.elementNum;
    pData = new int[elementNum + 1];
    for (unsigned int x = 0; x < elementNum; x++)
    {
        pData[x] = theOther.pData[x];
    }
    pData[elementNum] = '\0';
}

// clears the array
void Vector::clear()
{
    elementNum = 0;
    delete[]pData;
    pData = NULL;
}

// erases (deletes) the array element with the given index;
// valid indices: from 0 to size-1
void Vector::erase(unsigned int position)
{
    if ((position < 0) || (position >= elementNum))
    {
        throw std::out_of_range("Vector index out of range!");
    }
    else
    {
        int* temp = new int[elementNum];
        int y = 0;
        for (unsigned int x = 0; x < position; x++)
        {
            temp[x] = pData[x];
        }
        for (unsigned int x = position + 1; x < elementNum; x++)
        {
            temp[x - 1] = pData[x];
        }
        temp[elementNum - 1] = '\0';
        delete[] pData;
        pData = temp;
        elementNum--;
    }
}
// returns the array element with the given index, making possible to modify the element;
// valid indices: between 0 and size()-1
int& Vector::at(unsigned int position)
{
    if ((position >= 0) && (position < elementNum))
    {
        return pData[position];
    }
    else
    {
        throw std::out_of_range("Vector index out of range!");
    }
}

// returns the array element with the given index, without possibility to modify the element (see const keyword)
// valid indices: between 0 and size()-1
const int& Vector::at(unsigned int position)const
{
    if ((position < elementNum))
    {
        return pData[position];
    }
    else
    {
        throw std::out_of_range("Vector index out of range!");
    }
}

// inserts a new element into a place with the given index;
// if the index exceeds the array size, then the size should be increased, and the empty places should be filled with 0 (zero)
bool Vector::insert(unsigned int position, int element)
{
    if ((position < 0))
    {
        throw std::out_of_range("Vector index out of range!");
    }
    else if ((position < elementNum))
    {
        int* temp = new int[elementNum + 2];// 1 new index for new element, and one for '\0
        for (unsigned int x = 0; x < position; x++)
        {
            temp[x] = pData[x];
        }
        temp[position] = element;
        for (unsigned int x = position; x < elementNum; x++)
        {
            temp[x + 1] = pData[x];
        }
        temp[elementNum + 1] = '\0';
        delete[] pData;
        pData = temp;
        elementNum++;
        return true;
    }

    else
    {
        int* temp = new int[position + 2];// 1 new index for new element, and one for '\0'
        int y = 0;
        for (unsigned int x = 0; x < elementNum; x++)
        {
            temp[x] = pData[x];
        }
        for (unsigned int x = elementNum; x < position; x++)
        {
            temp[x] = 0;
        }
        temp[position] = element;
        temp[position + 1] = '\0';
        delete[] pData;
        pData = temp;
        elementNum = position + 1;
        return false;
    }
}

// Operator=
const Vector& Vector::operator=(const Vector& theOther)
{
    this->elementNum = theOther.elementNum;
    this->pData = new int[elementNum + 1];
    for (unsigned int x = 0; x < elementNum; x++)
    {
        this->pData[x] = theOther.pData[x];
    }
    pData[elementNum] = '\0';

    return *this;
}

// operator[]
int& Vector::operator[](unsigned int position)
{
    return pData[position];
}
const int& Vector::operator[](unsigned int position)const
{
    return pData[position];
}

// global function for printing vector data
std::ostream& operator << (std::ostream& os, const Vector& v)
{
    for (unsigned int x = 0; x < v.elementNum; x++)
    {
        os << v.at(x) << " ";
    }
    os << std::endl;
    return os;
}
