#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal{
public:
	Cat();
	~Cat();
	Cat(const Cat &);

	Cat& operator=(const Cat &rhs);


	void makeSound() const;
	std::string getType() const;

private:
	Brain* brain; //falta dar start a isto
};



#endif