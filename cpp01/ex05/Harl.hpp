# ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {

private :
	void	debug();
	void	info();
	void	warning();
	void	error();
	void	(Harl::*_f[4])(void);
	std::string	_lvl[4];

public :
	Harl();
	~Harl();
	void	complain(std::string level);
};

#endif