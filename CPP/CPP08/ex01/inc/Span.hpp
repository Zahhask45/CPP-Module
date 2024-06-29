#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class Span{
private:
	std::vector<int> vec;
	unsigned int vec_size;
	Span();
public:
	Span(unsigned int N);
	Span(const Span &);
	~Span();
	Span &operator=(const Span &rhs);

	void addNumber(const int value);
	void addRangeIter(std::vector<int>::iterator first, std::vector<int>::iterator last);
	int shortestSpan();
	int longestSpan();


	class SpanFullException : public std::exception {
        virtual const char *what() const throw();
    };

	class NotEnoughItemsException : public std::exception {
        virtual const char *what() const throw();
    };

	const std::vector<int> *getVec()const;
};
std::ostream &operator<<(std::ostream &os, const Span & sp);

#endif
