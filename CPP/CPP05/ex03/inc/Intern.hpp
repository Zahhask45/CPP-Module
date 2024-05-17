#ifndef INTERN_HPP
#define INTERN_HPP

#include "colors.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
public:
	Intern();
	Intern(const Intern &);
	~Intern();

	Intern &operator=(const Intern &rhs);
	AForm *makeForm(const std::string &form_name, const std::string &traget);

	AForm *pardonForm(const std::string &target);
	AForm *robotomyForm(const std::string &target);
	AForm *shrubberyForm(const std::string &target);
};


#endif
