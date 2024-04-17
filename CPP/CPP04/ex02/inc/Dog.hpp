#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal{
public:
	Dog();
	~Dog();
	Dog(const Dog &);

	Dog& operator=(const Dog &rhs);

	void makeSound() const;
	std::string getType() const;

private:
	Brain *brain; //falta dar start a isto
};



#endif