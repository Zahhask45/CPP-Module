#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *array, size_t size, void(*func)(T &)){
	if (!array || !func)
		return ;
	for (size_t i = 0; i < size; i++)
		func(array[i]);	
}

template<typename T>
void increment(T &x){x++;}

template<typename T>
void print(T &x){std::cout << x << std::endl;}

#endif
