# ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <map>

class Harl {

private :
	void	debug();
	void	info();
	void	warning();
	void	error();
	void	(Harl::*f[4])(void);
	std::map<const std::string, int> levelMap;

public :
	Harl();
	~Harl();
	void	complain(std::string level);
};

#endif