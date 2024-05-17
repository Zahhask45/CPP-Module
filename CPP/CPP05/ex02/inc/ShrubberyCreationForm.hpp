#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"

class AForm;

class ShrubberyForm: public AForm
{
private:
	const std::string _target;
public:
	ShrubberyForm();
	ShrubberyForm(const ShrubberyForm &);
	ShrubberyForm(const std::string &target);
	~ShrubberyForm();
	ShrubberyForm &operator=(const ShrubberyForm &rhs);


	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
    };
	class GradeTooHighException : public std::exception {
    	virtual const char *what() const throw();
    };
	//*Will create a File containing an ASCII tree
	virtual void formAction() const;

};





#endif
