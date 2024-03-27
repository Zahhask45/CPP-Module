#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "colors.hpp"

class Character: public ICharacter{
protected:
	AMateria *inventory[4];
	std::string Name;
public:
	Character();
	~Character(); // delete inventory
	Character(const Character &); // if invetory has content delete before adding new one
	Character(std::string);
};

#endif