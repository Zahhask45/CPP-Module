#include "Span.hpp"

int main() {
    Span sp1 = Span(4);
    sp1.addNumber(1);
    sp1.addNumber(20);
    sp1.addNumber(21);
    sp1.addNumber(100);

	std::cout << sp1.shortestSpan() << std::endl;

    return (0);
}
