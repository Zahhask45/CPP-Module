#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stddef.h>

template<typename T>
class Array
{
private:
	unsigned int _size;
	T* _arr;
public:
	Array(); //*Creates empty array
	Array(unsigned int n); //* Where n is the size of the array
	Array(const Array &); //* Modifying either the original array or its copy after copying musn’t affect the other array
	~Array();
	Array &operator=(const Array &rhs); //* Modifying either the original array or its copy after copying musn’t affect the other array
	T &operator[](const unsigned int index);
	unsigned int size() const;
};

#include "Array.tpp"

#endif
