#include "colors.hpp"

Ice::Ice(): type("ice"){
	std::cout << "[Ice constructor]" << std::endl;
}

Ice::~Ice(){
	std::cout << "[Ice destructor]" << std::endl;
}

Ice::Ice(const Ice &src){
	std::cout << "[Ice copy constructor]" << std::endl;
}

AMateria *Ice::clone() const{
	AMateria *NewMateria = new Ice();

	return NewMateria;
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
