#include "PmergeMe.hpp"

int main(int argc, char **argv){
	if (argc < 2){
		std::cout << "Needs arguments" << std::endl;
		return 1;
	}

	PmergeMe FJ(argv + 1); //* FJ from Ford-Johnson 
	
}



