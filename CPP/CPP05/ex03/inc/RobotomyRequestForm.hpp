#ifndef	ROBOTOMYREQUESTFORM_HPP
#define	ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"

class AForm;

class RobotomyForm: public AForm
{
private:
	const std::string _target;
public:
	RobotomyForm();
	RobotomyForm(const RobotomyForm &);
	RobotomyForm(const std::string &target);
	~RobotomyForm();
	RobotomyForm &operator=(const RobotomyForm &rhs);

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
    };
	class GradeTooHighException : public std::exception {
    	virtual const char *what() const throw();
    };
	//* WILL PRINT SOUND?
	virtual void formAction() const;
};


#endif
