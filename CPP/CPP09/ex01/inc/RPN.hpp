#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>

class RPN
{
private:
	std::stack<float> rpn; //* PROBABLY SHOULD NOT HAVE THIS HERE OR DO
public:
	RPN();
	RPN(const RPN &);
	~RPN();
	RPN &operator=(const RPN &rhs);

	bool parse(const std::string &arg);
	void read(const std::string &arg);
	void calculate(const char &signal);
};




#endif
