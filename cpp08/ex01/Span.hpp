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

	int&	operator[](int n);

	unsigned int		getMax() const;
	std::vector<int>	getVector() const;
	int					getSize() const;
	
	void				addNumber(const int n);
	void				addMaxNumbers();
	
	int	shortestSpan() const;
	int	longestSpan() const;

	class	MaxNumbersReach : public std::exception {
		public :
			virtual const char* what() const throw();
	};

	class	LessThanTwoNumbers : public std::exception {
		public :
			virtual const char* what() const throw();
	};
};

#endif