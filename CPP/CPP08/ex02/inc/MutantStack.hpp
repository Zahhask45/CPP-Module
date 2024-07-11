#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

//* The stack object inherits from the deque type
template<typename T, class container=std::deque<T> >
class MutantStack: public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack&);
	~MutantStack();
	MutantStack &operator=(const MutantStack& rhs);

	typedef typename container::iterator iterator;

	//* The c in c.begin() and c.end() is a container_type defined in the stack class
	//* It will be something like this: MutantStack -> std::stack -> std::deque
	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"

#endif
