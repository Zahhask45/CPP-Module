#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <time.h>

RobotomyForm::RobotomyForm(){}
RobotomyForm::~RobotomyForm(){}
RobotomyForm::RobotomyForm(const RobotomyForm &src):AForm(src){}
RobotomyForm::RobotomyForm(const std::string &target):AForm("RobotomyRequestForm", 72, 45), _target(target){}

//! NEEDS MORE TESTS
RobotomyForm &RobotomyForm::operator=(const RobotomyForm &rhs){
	if (this != &rhs)
		*this = rhs;
	return *this;
}

//* EXCEPTIONS

const char *RobotomyForm::GradeTooHighException::what() const throw(){
	return ("Grade to High");
}

const char *RobotomyForm::GradeTooLowException::what() const throw(){
	return ("Grade to Low");
}

void RobotomyForm::formAction() const{
	std::cout << "*Makes some drilling noise*" << std::endl;

	srand(time(NULL));
	
	//* between 0 and 1
	int fifty =rand() % 2;
	
	if (fifty)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "robotomy failed miserably" << std::endl;
}

