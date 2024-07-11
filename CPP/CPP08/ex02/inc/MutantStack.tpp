#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template<typename T, class container>
MutantStack<T, container>::MutantStack(){}

template<typename T, class container>
MutantStack<T, container>::~MutantStack(){}

template<typename T, class container>
MutantStack<T, container>::MutantStack(const MutantStack<T, container> &src){*this = src;}
template<typename T, class container>
MutantStack<T,container> &MutantStack<T, container>::operator=(const MutantStack<T, container>& rhs){
	if (this != &rhs) {
        this->c = rhs.c;
    }
	return *this;
}

template<typename T, class container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::begin(){
	return this->c.begin();
}
template<typename T, class container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::end(){
	return this->c.end();
}


#endif
