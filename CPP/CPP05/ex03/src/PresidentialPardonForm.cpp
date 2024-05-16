#include "PresidentialPardonForm.hpp"

PresidentialForm::PresidentialForm(){}
PresidentialForm::~PresidentialForm(){}
PresidentialForm::PresidentialForm(const PresidentialForm &src):AForm(src){}
PresidentialForm::PresidentialForm(const std::string &target):AForm("PresidentialPardonForm", 25, 5), _target(target){}

//! NEED MOPE TESTS
PresidentialForm &PresidentialForm::operator=(const PresidentialForm &rhs){
	if (this != &rhs)
		*this = rhs;
	return *this;
}

const char *PresidentialForm::GradeTooHighException::what() const throw(){
	return ("Grade to High");
}

const char *PresidentialForm::GradeTooLowException::what() const throw(){
	return ("Grade to Low");
}

void PresidentialForm::formAction() const{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

