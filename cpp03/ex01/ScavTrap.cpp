#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "Default ScavTrap constuctor called" << std::endl;
	this->_name = "defaultName";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& src) {
	std::cout << "Copy ScavTrap constuctor called" << std::endl;
	*this = src;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "Parametric ScavTrap constuctor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "ScavTrap " + this->_name + " attack " + target + " causing " 
		<< this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
		if (this->_energyPoints < 1)
			std::cout << this->_name + " is exhausted" << std::endl;
	}
}

void	ScavTrap::guardGate() {
	if (this->_hitPoints > 0) {
		std::cout << "ScavTrap " + this->_name + " is now in Gate keeper mode" << std::endl;
	}
}