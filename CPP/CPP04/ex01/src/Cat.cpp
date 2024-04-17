#include "Cat.hpp"

Cat::Cat(): Animal(){
	this->type = "Cat";
	this->brain = new Brain("Cat");
	std::cout << _CYAN << "[Cat contructor]" << _END << std::endl;
}

Cat::~Cat(){
	delete this->brain;
	std::cout << _CYAN << "[Cat destructor]" << _END << std::endl;
}

Cat::Cat(const Cat &src): Animal(){
	std::cout << _CYAN << "[Cat copy constructor]" << _END << std::endl;
	*this = src;
}

Cat &Cat::operator=(const Cat &rhs){
	std::cout << _CYAN << "[Cat operator=]" << _END << std::endl;
	if(this != &rhs)
	{
		this->type = rhs.type;
		this->brain = new Brain(*(rhs.brain));
	}
	return *this;
}

void Cat::makeSound() const{
	std::cout << _CYAN << "[Cat makeSound] Meow Meow" << _END << std::endl;
}

std::string Cat::getType() const {
	return this->type;
}
