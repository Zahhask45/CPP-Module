#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _sign;
	const int _grade_sign;
	const int _grade_exec;
public:
	AForm();
	AForm(const AForm &);
	AForm(const std::string &name, int grade_sign, int grade_exec);
	virtual ~AForm();

	std::string get_name() const;
	bool get_sign();
	int get_grade_sign() const;
	int get_grade_exec() const;

	AForm &operator=(const AForm &rhs);

	void beSigned(const Bureaucrat &src);
	void execute(Bureaucrat const  & executor) const;

	//! This is ONLY to be used on the concrete classes to do what they are suppose to do according to the subject
	virtual void formAction() const = 0;

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
    };
	class GradeTooHighException : public std::exception {
    	virtual const char *what() const throw();
    };
	class GradeNotSignedException : public std::exception {
		virtual const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &, const AForm &obj);

#endif
