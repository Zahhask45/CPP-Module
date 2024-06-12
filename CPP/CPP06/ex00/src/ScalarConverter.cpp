#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &src){*this = src;}
ScalarConverter::~ScalarConverter(){}



//* Detect which literal I received: CHAR, INT, FLOAT and DOUBLE
//* To find if is CHAR: lenght = 1 and needs to be between 33 and 126 and can't me a number
//* To find if is INT: is only numbers or digits, does not contain a char neither a f or a "." 
//* 


//* DIFFERENT FOR POSITIVE INT AND NEGATIVE INT


//* This function can return a string with the type that it is and in the convert fuction will do the rest
//! NEED TO TAKE CARE OF nan AND inf AND inff
int ScalarConverter::detect(const std::string &str){
	size_t l = str.length();
	int ischar = 0;
	int issign = 0;
	int isint = 0;
	int isfloat = 0;
	int isdouble = 0;
	int isdot = 0;

	if (l == 1){
		if (!isdigit(static_cast<unsigned char>(str[0])) && isascii(static_cast<unsigned char>(str[0])))
			return CHAR;
			//ischar = 1; // return saying that it is a char
		if (isdigit(static_cast<unsigned char>(str[0])))
			return INT;
			//isint = 1; // return saying that it is a int
	}

	for (size_t i = 0; i < l; i++){
		if ((str[i] == '-' || str[i] == '+')){ //! CHECK LATER
			if (issign == 1 || (i > 0 && !(str[i - 1] == '-' || str[i - 1] == '+')))
				return 0; //! RETURN ERROR
			issign++;
		}
		else if (str[i] == '.'){
			if (isdot == 1)
				return 0; //! RETURN ERROR
			isdot++;
		}
		else if (!isdigit(static_cast<unsigned char>(str[i])) && isascii(static_cast<unsigned char>(str[i]))){
			ischar++;
		}
	}
	// std::cout << "dot: " << isdot << std::endl;
	// std::cout << "chars: " << ischar << std::endl;

	if (isdot == 0 && ischar == 0)
		return INT;
		//isint = 1; // return int
	if (isdot == 1 && ischar == 0)
		return DOUBLE;
		//isdouble = 1; // return double
	if (isdot == 1 && ischar == 1 && str[l - 1] == 'f')
		return FLOAT;
		//isfloat == 1; // return float
	
	
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
	// std::cout << "type: " << type << std::endl << std::endl;
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
	std::cout << "int: " << i << std::endl;

	float f = static_cast<float>(d);
	std::cout << "float: " << std::fixed << std::setprecision(precision) << f << "f" << std::endl;

	std::cout << "double: " << std::fixed << std::setprecision(precision) << d << std::endl;

	return 0;
}

/*

void *ScalarConverter::convertToInt(const std::string &str){
	double d = static_cast<double>(atof(str.c_str()));

	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::max()
			|| std::isnan(d) || std::isinf(d))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	return 0;
}

void *ScalarConverter::convertToFloat(const std::string &str){
	double d = static_cast<double>(atof(str.c_str()));
	
	if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
		std::cout << "IMPOSSIBLE" << std::endl;
	else
		std::cout << static_cast<float>(d) << "f" << std::endl;
	return 0;
}

void *ScalarConverter::convertToDouble(const std::string &str){
	double d = static_cast<double>(atof(str.c_str()));

	std::cout << d << std::endl;
	return 0;
} */



