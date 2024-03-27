#ifndef ICE_HPP
#define ICE_HPP

#include "colors.hpp"

class Ice: public AMateria{
public:
	Ice();
	~Ice();
	Ice(const Ice &);

	AMateria* clone() const;
	void use(ICharacter& target);

protected:
	std::string type; // type will be "ice" not anything else
};

#endif