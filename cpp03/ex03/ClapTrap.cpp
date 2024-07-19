#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default ClapTrap constuctor called" << std::endl;
	this->_name = "defaultName";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
	std::cout << "Copy ClapTrap constuctor called" << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << "Parametric ClapTrap constuctor called" << std::endl;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "ClapTrap " + this->_name + " attack " + target + " causing " 
		<< this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
		if (this->_energyPoints < 1)
			std::cout << this->_name + " is exhausted" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > 0) {
		std::cout << "ClapTrap " + this->_name + " take "
		<< amount << " damage" << std::endl;
		this->_hitPoints -= amount;
		if (this->_hitPoints < 1)
			std::cout << this->_name + " is dead" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << "ClapTrap " + this->_name + " gets "
		<< amount << " hit points back" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
		if (this->_energyPoints < 1)
			std::cout << this->_name + " is exhausted" << std::endl;
	}
}

void	ClapTrap::printInfo() const {
	std::cout << std::endl << this->_name + " :" << std::endl;
	std::cout << "Hit points left : " << this->_hitPoints << std::endl;
	std::cout << "Energy points left : " << this->_energyPoints << std::endl;
	std::cout << "Attack damage : " << this->_attackDamage << std::endl << std::endl;
}

void	ClapTrap::setName(std::string name) {
	this->_name = name;
}