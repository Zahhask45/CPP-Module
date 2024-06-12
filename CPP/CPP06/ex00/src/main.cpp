#include "ScalarConverter.hpp"



//* I'm going to receive a literal from the argv and I have to detect which one is
//* If I receive a INT, I convert the string to the INT and then convert the INT to the others
//* EXEMPLE:
//*
//* STRING TO INT
//* INT TO CHAR
//* INT TO FLOAT
//* INT TO DOUBLE
//*
//* And the same for the others
int main(int argc, char **argv){
	ScalarConverter *test = NULL;

	if (argc < 2){
		std::cout << "Need 1 argument" << std::endl;
		return 1;
	}
	test->convert(argv[1]);

	return 0;
}
