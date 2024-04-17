#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "colors.hpp"

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &);
	~Bureaucrat();

	void GradeTooHighException(int grade);
	void GradeTooLowException(int grade);
};


#endif