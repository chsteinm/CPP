# ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <new>

class Zombie {

private :
	std::string _name;

public :
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void	annonce() const;
	Zombie*	zombieHorde(int N, std::string name) const;
};

#endif