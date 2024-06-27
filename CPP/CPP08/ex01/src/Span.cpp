#include "Span.hpp"

Span::Span(){}
Span::Span(unsigned int N){this->vec.reserve(N);}
Span::Span(const Span &src){
	*this = src;
}

Span::~Span(){}

Span &Span::operator=(const Span &rhs){
	if (this != &rhs) {
        this->vec = rhs.vec;
    }

    return *this;
}

void Span::addNumber(const int value){
	vec.push_back(value);
}

int Span::shortestSpan(){
	if (this->vec.size() < 2)
        throw Span::NotEnoughItemsException();

    std::vector<int>::iterator it;

    std::vector<int> copy(this->vec);
    std::sort(copy.begin(), copy.end());

    int shortest = abs(*(copy.begin() + 1) - *copy.begin());

    for (it = copy.begin(); it != copy.end() - 1; ++it) {
        if (abs(*(it + 1) - *it) < shortest) {
            shortest = abs(*(it + 1) - *it);
        }
    }
    return shortest;
}

int Span::longestSpan(){
	if (vec.size() < 2){
		throw Span::NotEnoughItemsException();
	}

	int min = *std::min_element(vec.begin(), vec.end());
	int max = *std::max_element(vec.begin(), vec.end());

	return std::abs(max - min);
}


const char *Span::SpanFullException::what() const throw() {
    return ("Span is full");
}

const char *Span::NotEnoughItemsException::what() const throw() {
    return ("Not enough items in the Span");
}


