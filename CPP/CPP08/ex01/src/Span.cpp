#include "Span.hpp"

Span::Span(){}
Span::Span(unsigned int N){
	this->vec.reserve(N);
	this->vec_size = N;
}
Span::Span(const Span &src){
	*this = src;
}

Span::~Span(){}

Span &Span::operator=(const Span &rhs){
	if (this != &rhs) {
        this->vec = rhs.vec;
		this->vec_size = rhs.vec_size;
    }

    return *this;
}

void Span::addNumber(const int value){
	vec.push_back(value);
}

//! MISSING STUFF
void Span::addRangeIter(std::vector<int>::iterator first, std::vector<int>::iterator last){
	if (vec.capacity() - vec.size() < static_cast<size_t>(std::distance(first, last)))
		throw Span::SpanFullException();

	this->vec.insert(vec.end(), first, last);
}



int Span::shortestSpan(){
	if (this->vec.size() < 2)
        throw Span::NotEnoughItemsException();

    std::vector<int>::iterator it;

    std::vector<int> copy(this->vec);
    std::sort(copy.begin(), copy.end());

    int shortest = abs(*(copy.begin() + 1) - *copy.begin());

	it = copy.begin();
	while (it != copy.end() - 1 && shortest != 0){
		if (abs(*(it + 1) - *it) < shortest){
			shortest = abs(*(it + 1) - *it);
		}
		it++;
	}
    return shortest;
}

int Span::longestSpan(){
	if (vec.size() < 2){
		throw Span::NotEnoughItemsException();
	}

	int min = *min_element(vec.begin(), vec.end());
	int max = *max_element(vec.begin(), vec.end());

	return abs(max - min);
}


const char *Span::SpanFullException::what() const throw() {
    return ("Span is full");
}

const char *Span::NotEnoughItemsException::what() const throw() {
    return ("Not enough items in the Span");
}

const std::vector<int> *Span::getVec()const {
	return &vec;
}

std::ostream &operator<<(std::ostream &os, const Span& sp){
	 for ( std::vector<int>::const_iterator it = sp.getVec()->begin(); it != sp.getVec()->end(); ++it )
        os << *it << " ||  ";
    return os;
}
