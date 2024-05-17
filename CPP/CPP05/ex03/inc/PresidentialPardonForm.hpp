#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"

class AForm;

class PresidentialForm: public AForm
{
private:
	const std::string _target;
public:
	PresidentialForm();
	PresidentialForm(const PresidentialForm &);
	PresidentialForm(const std::string &target);
	~PresidentialForm();

	PresidentialForm &operator=(const PresidentialForm &rhs);
	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
    };
	class GradeTooHighException : public std::exception {
    	virtual const char *what() const throw();
    };
	//*Will Pardon the target
	virtual void formAction() const;
};

#endif
