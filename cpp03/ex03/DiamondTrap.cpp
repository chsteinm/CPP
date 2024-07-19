#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "Default DiamondTrap constuctor called" << std::endl;
	this->_name = "defaultName";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) {
	std::cout << "Copy DiamondTrap constuctor called" << std::endl;
	*this = src;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	std::cout << "Parametric DiamondTrap constuctor called" << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

void	DiamondTrap::whoAmI() {
	if (this->_hitPoints > 0) {
		std::cout << "My name is " + this->_name + ", I'm the child of " + ClapTrap::_name << std::endl;
	}
}