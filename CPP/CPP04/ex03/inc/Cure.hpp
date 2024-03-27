#ifndef CURE_HPP
#define CURE_HPP

#include "colors.hpp"

class Cure: public AMateria{
public:
	Cure();
	~Cure();
	Cure(const Cure &);

	void clone(void); //Again need to change this later when i discover what it is
	void use(ICharacter&);
	
protected:
	std::string type; // will be "cure"
};

#endif