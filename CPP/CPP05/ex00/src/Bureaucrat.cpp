#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
	throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name), _grade(src._grade){
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}


Bureaucrat::~Bureaucrat(){
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs){
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}



std::string Bureaucrat::getName() const {return this->_name;}
int Bureaucrat::getGrade() const{return this->_grade;}



void Bureaucrat::increment(){
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrement(){
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade too Low");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &obj){
	o << obj.getname() << ", bureaucrat grade " << obj.getgrade();

	return o;
}
