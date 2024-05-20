#include "Form.hpp"

Form::Form():_name("Sheet 1"), _sign(false), _grade_sign(10), _grade_exec(15){}

Form::Form(const std::string &name, int grade_sign, int grade_exec)
	:_name(name), _sign(false), _grade_sign(grade_sign), _grade_exec(grade_exec){
	if (_grade_sign < 1)
		throw Form::GradeTooHighException();
	if (_grade_sign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src)
	:_name(src._name), _sign(src._sign), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec){
}

Form::~Form(){}

Form &Form::operator=(const Form &rhs){
	if (this != &rhs)
		*this = rhs;
	return (*this);
}


//* Just the Getters *//
std::string Form::get_name() const{
	return this->_name;
}

bool Form::get_sign(){
	return this->_sign;
}

int Form::get_grade_sign() const{
	return this->_grade_sign;
}

int Form::get_grade_exec() const{
	return this->_grade_exec;
}

int Form::get_sign() const{
	return this->_sign;
}

void Form::beSigned(const Bureaucrat &src){
	if (this->_grade_sign < src.getgrade())
		throw Form::GradeTooLowException();
	this->_sign = true;
}

std::ostream &operator<<(std::ostream &o, const Form &obj){
	o << obj.get_name() << ", Form grade needed to sign " << obj.get_grade_sign() << ", grade needed to execute "
		<< obj.get_grade_exec();
	if (obj.get_sign())
		o << " and form is signed" << std::endl;
	else
		o << " and form is not signed" << std::endl;
	return o;
}

const char *Form::GradeTooHighException::what() const throw() {
    return ("Grade too High");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("Grade too Low");
}

