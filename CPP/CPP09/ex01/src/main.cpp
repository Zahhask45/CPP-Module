#include "RPN.hpp"


int main(int argc, char** argv){
	if (argc != 2){
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	try{
		RPN why;
		why.read(argv[1]);
	}
	catch(const std::exception& e){
	}
	


	return 0;
}


