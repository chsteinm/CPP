# ifndef Span_HPP
#define Span_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <limits>
#include <exception>
#include <ctime>
#include <cstdlib>

class Span {
private :
	unsigned int	_max;
	std::vector<int> _numbers;

public :
	Span();
	Span(unsigned int n);
	Span(const Span& src);
	~Span();
	Span&	operator=(const Span& src);

	unsigned int	getMax() const;
	void			addNumber(const int n);
	void			addMaxNumbers();

	class	MaxNumbersReach : public std::exception {
		public :
			virtual const char* what() const throw();
	};
};

#endif