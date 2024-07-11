#include "BitcoinExchange.hpp"

//* If file is txt delimeter will be '|'
int main(int argc, char **argv){

	(void)argv;
	if (argc != 2){
		std::cout << "Wrong amount of arguments(only 1 argument)" << std::endl;
		return 1;
	}

	try{
		BitcoinExchange btc;
		btc.parseFile(argv[1]);
	}
	catch(const std::exception& e){
	}
	
	return 0;
}


