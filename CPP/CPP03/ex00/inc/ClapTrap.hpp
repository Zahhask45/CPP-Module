#ifndef CLAPRAP_HPP
#define CLAPRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string name;
	int	health_points;
	int	energy_points;
	int	attack_damage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &);
	ClapTrap &operator=(const ClapTrap& rhs);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif