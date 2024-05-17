#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "colors.hpp"
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &);
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &rhs);

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
    };
	class GradeTooHighException : public std::exception {
    	virtual const char *what() const throw();
    };

	std::string getname() const;
	int getgrade() const;

	void increment();
	void decrement();

	void signForm(AForm &src) const;
	//! CAREFULL WITH THIS ONE I DONT KNOW IF IT NEEDS TO THROW A EXCEPTION
	void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &obj);

#endif
