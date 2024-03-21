#include "ScavTrap.hpp"

const int ScavTrap::scav_hp = 100;
const int ScavTrap::scav_ep = 50;
const int ScavTrap::scav_ad = 20;

ScavTrap::ScavTrap() : ClapTrap("SC4V-TP")
{
    this->health_points = ScavTrap::scav_hp;
    this->energy_points = ScavTrap::scav_ep;
    this->attack_damage = ScavTrap::scav_ad;
    std::cout << _RED << "ScavTrap Called from ClapTrap goes by the name: " << this->name << _END << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->health_points = ScavTrap::scav_hp;
    this->energy_points = ScavTrap::scav_ep;
    this->attack_damage = ScavTrap::scav_ad;
    std::cout << _RED << "ScavTrap Called from ClapTrap goes by the name: " << this->name << _END << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << _RED << "ScavTrap destroyed: " << this->name << _END << std::endl;
    return;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
}

void ScavTrap::guardGate()
{
    std::cout << _RED << "SC4V-TP: Halt, moon citizen! I've been chosen to stand out here - "
    << "far, far away from everyone else - to guard the main gate to the old communications facility. "
    << "It's a VERY important duty, as I'm not to let ANYONE in through here! "
    << "Unless, of course, you're here as fresh meat for the recruitment grinder!" << std::endl;
}