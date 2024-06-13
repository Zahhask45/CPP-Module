#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &src){*this = src;}
ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs){
	*this = rhs;
	return *this;
}

//* This function is in charge of detecting what literal the string received is
int ScalarConverter::detect(const std::string &str){
	size_t l = str.length();
	int ischar = 0;
	int issign = 0;
	int isint = 0;
	int isfloat = 0;
	int isdouble = 0;
	int isdot = 0;

	//* Verify if is a char or int
	if (l == 1){
		if (!isdigit(static_cast<unsigned char>(str[0])) && isascii(static_cast<unsigned char>(str[0])))
			return CHAR;
		if (isdigit(static_cast<unsigned char>(str[0])))
			return INT;
	}
	//! Verify MAX_INT and MIN_INT
	//* Parse the string received
	for (size_t i = 0; i < l; i++){
		if ((str[i] == '-' || str[i] == '+')){
			if (issign == 1 || (i > 0 && !(str[i - 1] == '-' || str[i - 1] == '+')))
				return 0; //! RETURN ERROR
			issign++;
		}
		else if (str[i] == '.'){
			if (isdot == 1)
				return 0; //! RETURN ERROR
			if (str[i + 1] == 'f' || str[i + 1] == '\0')
				return 0;
			isdot++;
		}
		else if (!isdigit(static_cast<unsigned char>(str[i])) && isascii(static_cast<unsigned char>(str[i]))){
			ischar++;
		}
	}
	double ver = static_cast<double>(atof(str.c_str()));
	//* Return respective literal types
	if (isdot == 0 && ischar == 0 && ver <= INT_MAX && ver >= INT_MIN)
		return INT;
	if (isdot == 1 && ischar == 0)
		return DOUBLE;
	if (isdot == 1 && ischar == 1 && str[l - 1] == 'f' && ver <= MAXFLOAT)
		return FLOAT;
	if (ver >= INT_MAX || ver <= INT_MIN)
		return DOUBLE;
	
	
	//* Detect if is nan or inf
	if (isint == 0 && isdouble == 0 && isfloat == 0){
		if (std::isnan(static_cast<double>(atof(str.c_str()))))
			return ISNAN;
		if (std::isinf(static_cast<double>(atof(str.c_str()))))
			return ISINF;
	}
	return 0;
}


void *ScalarConverter::convert(const std::string &str){
	int type;
	type = detect(str);
	switch (type)
	{
	case ISINF:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		break;
	case ISNAN:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		break;
	case CHAR:
		literalChar(str);
		break;
	case INT:
		literalInt(str);
		break;
	case FLOAT:
		literalFloat(str);
		break;
	case DOUBLE:
		literalDouble(str);
		break;
	default:
		std::cout << "Invalid input" << std::endl;
		break;
	}

	return 0;
}

void *ScalarConverter::literalChar(const std::string &str){
	char c = static_cast<char>(str[0]);
	std::cout << "char: '" << c << "'" << std::endl;

	int i = static_cast<int>(c);
	std::cout << "int: " << i << std::endl;

	float f = static_cast<float>(c);
	std::cout << "float: " << f << ".0f" << std::endl;

	double d = static_cast<double>(c);
	std::cout << "double: " << d << ".0" << std::endl;

	return 0;

}

void *ScalarConverter::literalInt(const std::string &str){
	int i = static_cast<int>(atof(str.c_str()));

	if (i > 32 && i < 127){
		char c = static_cast<char>(i);
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << i << std::endl;

	float f = static_cast<float>(i);
	std::cout << "float: " << f << ".0f" << std::endl;

	float d = static_cast<double>(i);
	std::cout << "double: " << d << ".0" << std::endl;

	return 0;
}

void *ScalarConverter::literalFloat(const std::string &str){
	float f = static_cast<float>(atof(str.c_str()));

	int precision = 0;
	int dot = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (dot == 1)
			precision++;
		if (str[i] == '.')
			dot = 1;
	}
	precision--; //* Remove the 'f'
	
	if (f > 32 && f < 127){
		char c = static_cast<char>(f);
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;

	int i = static_cast<int>(f);
	std::cout << "int: " << i << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(precision) << f << "f" << std::endl;

	double d = static_cast<double>(f);
	std::cout << "double: " << std::fixed << std::setprecision(precision) << d << std::endl;

	return 0;
}

void *ScalarConverter::literalDouble(const std::string &str){
	double d = static_cast<double>(atof(str.c_str()));
	int precision = 0;
	int dot = 0;


	for (size_t i = 0; i < str.length(); i++)
	{
		if (dot == 1)
			precision++;
		if (str[i] == '.')
			dot = 1;
	}

	if (d > 32 && d < 127){
		char c = static_cast<char>(d);
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;

	int i = static_cast<int>(d);
	if (d >= INT_MAX || d <= INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	float f = static_cast<float>(d);
	if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
		std::cout << "float: impossible" << std::endl;
	else if (precision > 0)
		std::cout << "float: " << std::fixed << std::setprecision(precision) << f << "f" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(precision) << f << ".0f" << std::endl;

	std::cout << "double: " << std::fixed << std::setprecision(precision) << d << std::endl;

	return 0;
}
