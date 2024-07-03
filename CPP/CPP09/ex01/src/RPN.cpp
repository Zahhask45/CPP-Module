#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(const RPN &src){*this = src;}
RPN::~RPN(){}

RPN &RPN::operator=(const RPN& rhs){
	if (this != &rhs) {
        this->rpn = rhs.rpn;
    }
    return *this;
}

//! MISSING STUFF
bool RPN::parse(const std::string &arg){
	int numbers = 0;
	int signals = 0;

	for (std::string::const_iterator it = arg.begin(); it != arg.end(); it++){
		if (std::isdigit(*it)){
			numbers++;
			continue;
		}

		if (*it == '+' || *it == '-' || *it == '*' || *it == '/'){
			signals++;
			continue;
		}
		return false;
	 }
	 if (numbers - signals != 1)
	 	return false;
	return true;
}


void RPN::read(const std::string &arg){

	std::string copy = arg;
	//* REMOVE THE SPACES ' '
	copy.erase(remove(copy.begin(), copy.end(), ' '), copy.end());

	if (!this->parse(copy)){
		std::cout << "Error" << std::endl;
		return;
	}

	 for (std::string::const_iterator it = copy.begin(); it != copy.end(); it++){
		if (std::isdigit(*it)){
			rpn.push(*it - '0'); //* Convert from ASCII
			continue;
		}

		if (*it == '+' || *it == '-' || *it == '*' || *it == '/'){
			this->calculate(*it);
			continue;
		}
	 }
	std::cout << rpn.top() << std::endl;
}

void RPN::calculate(const char &signal){
	float twond = rpn.top(); //* SECOND NUMBER
	rpn.pop();
	float onest = rpn.top(); //* FIRST NUMBER
	rpn.pop();

	switch (signal)
	{
	case '+':
		rpn.push(onest + twond);
		break;
	case '-':
		rpn.push(onest - twond);
		break;
	case '*':
		rpn.push(onest * twond);
		break;
	case '/':
		rpn.push(onest / twond);
		break;
	
	default:
		std::cout << "Unexpected error." << std::endl;
		std::cout << "How am I being printed?" << std::endl << "Answer: I'm cooked" << std::endl;
		break;
	}
}

