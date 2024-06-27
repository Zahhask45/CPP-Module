#include "Intern.hpp"

Intern::Intern(){}
Intern::~Intern(){}
Intern::Intern(const Intern &src){*this = src;}


Intern &Intern::operator=(const Intern &rhs){
	(void)rhs;
	return *this;
}

AForm *Intern::pardonForm(const std::string &target){
	return new PresidentialForm(target);
}

AForm *Intern::robotomyForm(const std::string &target){
	return new RobotomyForm(target);
}

AForm *Intern::shrubberyForm(const std::string &target){
	return new ShrubberyForm(target);
}



AForm *Intern::makeForm(const std::string &form_name, const std::string &target){
	AForm *(Intern::*memberFuncs[])(const std::string &target) = {
		&Intern::pardonForm, &Intern::robotomyForm, &Intern::shrubberyForm};

	std::string formTypes[] = {"shrubbery", "robotomy", "pardon"};

	for (size_t i = 0; i < 3; i++){
		if (form_name == formTypes[i]){
			return ((this->*memberFuncs[i])(target));
		}
	}
	std::cout << "Form not founded" << std::endl;
	return NULL;
}


