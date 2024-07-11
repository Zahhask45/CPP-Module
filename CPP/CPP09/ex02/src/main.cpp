#include "PmergeMe.hpp"

int main(int argc, char **argv){
	if (argc < 3){
		std::cout << "Needs more arguments" << std::endl;
		return 1;
	}

	PmergeMe FJ(argv + 1); //* FJ from Ford-Johnson 
	
}



