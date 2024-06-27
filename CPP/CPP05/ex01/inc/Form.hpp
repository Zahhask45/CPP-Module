#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _sign;
	const int _grade_sign;
	const int _grade_exec;
public:
	Form();
	Form(const Form &);
	Form(const std::string &name, int grade_sign, int grade_exec);
	~Form();

	std::string get_name() const;
	bool get_sign();
	int get_grade_sign() const;
	int get_grade_exec() const;

	Form &operator=(const Form &rhs);

	void beSigned(const Bureaucrat &src);

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
    };
	class GradeTooHighException : public std::exception {
    	virtual const char *what() const throw();
    };

};

std::ostream &operator<<(std::ostream &, const Form &obj);

#endif
