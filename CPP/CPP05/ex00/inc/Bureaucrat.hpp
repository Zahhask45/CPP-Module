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
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &rhs);

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
    };
	class GradeTooHighException : public std::exception {
    	virtual const char *what() const throw();
    };

	std::string getName() const;
	int getGrade() const;

	void increment();
	void decrement();
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &obj);

#endif
