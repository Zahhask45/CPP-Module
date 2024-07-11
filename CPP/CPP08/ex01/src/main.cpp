#include "Span.hpp"

int gen(){
	return std::rand() % (1000 + 1);
}

int main(){
	try{

		std::vector<int> ve(10);
		std::srand(time(NULL));
		std::generate(ve.begin(), ve.end(), gen);

		Span sp = Span(10);

		sp.addNumber(10);
		sp.addRangeIter(ve.begin(), ve.end());

		std::cout << sp << std::endl;

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
