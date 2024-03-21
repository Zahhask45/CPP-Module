#ifndef CLAPRAP_HPP
#define CLAPRAP_HPP

#define _END			"\033[0m"
#define _BOLD			"\033[1m"
#define _UNDER			"\033[4m"

#define _REV			"\033[7m"
#define _BLACK			"\033[1;30m"
#define _RED			"\033[1;31m"
#define _GREEN			"\033[1;32m"
#define _YELLOW			"\033[1;33m"
#define _BLUE			"\033[1;34m"
#define _PURPLE			"\033[1;35m"
#define _CYAN			"\033[1;36m"
#define _WHITE			"\033[1;37m"

#include <iostream>
#include <string>

class ClapTrap
{
protected:
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
	std::string getName();
	int getEnergy();
	int getHp();
	void setEnergy(int new_energy);
};


#endif