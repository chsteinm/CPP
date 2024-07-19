# ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

protected :
	std::string		_name;
	int	_hitPoints;
	int	_energyPoints;
	int	_attackDamage;

public :
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& src);
	virtual ~ClapTrap();
	ClapTrap&	operator=(const ClapTrap& src);
	
	virtual void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	printInfo() const;
	void	setName(std::string name);
};

#endif