#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "colors.hpp"
#define CHAR 1
#define INT 2
#define DOUBLE 3
#define FLOAT 4
#define ISNAN -1
#define ISINF -2

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
public:
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &rhs);
	static void *convert(const std::string &str);
	static void *literalChar(const std::string &str);
	static void *literalInt(const std::string &str);
	static void *literalFloat(const std::string &str);
	static void *literalDouble(const std::string &str);

	static int detect(const std::string &str);

};

#endif
