#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <stddef.h>
#include <stdexcept>
#include "Array.hpp"

#ifndef ARRAY_HPP
#error "You must include Array.hpp before Array.tpp"
#endif


template<typename T>
Array<T>::Array(): _size(0), _arr(NULL) {}

template<typename T>
Array<T>::Array(unsigned int n): _size(n), _arr(new T[n]()) {} 

template<typename T>
Array<T>::Array(const Array<T> &src): _size(src._size), _arr(new T[src._size]()){
	for (size_t i = 0; i < _size; i++)
		_arr[i] = src._arr[i];
}

template<typename T>
Array<T>::~Array(){
	delete []_arr;
}


template<typename T>
static void swap(T &src1, T &src2){
	T temp = src1;
	src1 = src2;
	src2 = temp;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &rhs){
	Array temp(rhs);
	swap(_size, temp._size);
	swap(_arr, temp._arr);
	return *this;
}

template<typename T>
T &Array<T>::operator[](const unsigned int index){
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _arr[index];
}

template<typename T>
unsigned int Array<T>::size() const {
	return _size;
}

#endif
