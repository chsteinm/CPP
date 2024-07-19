#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "Default FragTrap constuctor called" << std::endl;
	this->_name = "defaultName";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& src) {
	std::cout << "Copy FragTrap constuctor called" << std::endl;
	*this = src;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "Parametric FragTrap constuctor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

void	FragTrap::highFivesGuys() {
	if (this->_hitPoints > 0) {
		std::cout << "FragTrap " + this->_name + " : High fives guys !!! :D" << std::endl;
	}
}