#include "AForm.hpp"

AForm::AForm():_name("Sheet 1"), _sign(false), _grade_sign(10), _grade_exec(15){}

AForm::AForm(const std::string &name, int grade_sign, int grade_exec)
	:_name(name), _sign(false), _grade_sign(grade_sign), _grade_exec(grade_exec){
	if (_grade_sign < 1)
		throw AForm::GradeTooHighException();
	if (_grade_sign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src)
	:_name(src._name), _sign(src._sign), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec){
}

AForm::~AForm(){}

AForm &AForm::operator=(const AForm &rhs){
	if (this != &rhs)
		*this = rhs;
	return (*this);
}


//* Just the Getters *//
std::string AForm::get_name() const{
	return this->_name;
}

bool AForm::get_sign(){
	return this->_sign;
}

int AForm::get_grade_sign() const{
	return this->_grade_sign;
}

int AForm::get_grade_exec() const{
	return this->_grade_exec;
}


//*Sign the Form or not
void AForm::beSigned(const Bureaucrat &src){
	if (this->_grade_sign < src.getgrade())
		throw AForm::GradeTooLowException();
	this->_sign = true;
}

//*Execute the Form or not
void AForm::execute(Bureaucrat const & executor) const{
	if (this->_sign == false)
		throw AForm::GradeNotSignedException();
	if (executor.getgrade() > this->_grade_exec)
		throw AForm::GradeTooLowException();
	this->formAction();
}


std::ostream &operator<<(std::ostream &o, const AForm &obj){
	o << obj.get_name() << ", AForm grade needed to sign" << obj.get_grade_exec();
	return o;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return ("Grade too High");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("Grade too Low");
}

const char *AForm::GradeNotSignedException::what() const throw() {
	return ("Grade not Signed");
}
