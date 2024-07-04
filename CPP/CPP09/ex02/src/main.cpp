#include "PmergeMe.hpp"

int main(int argc, char **argv){
	if (argc < 2){
		std::cout << "Needs arguments" << std::endl;
		return 1;
	}

	PmergeMe FJ; //* FJ from Ford-Johnson 

	FJ.parse(argv + 1);

	std::cout << FJ << std::endl;
	
}



