#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
private:
	T arr[];
public:
	Array();
	Array(unsigned int n); //* Where n is the size of the array
	Array(const Array &);
	~Array();
	Array &operator=(const Array &rhs);
};


#endif
