# ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data {
	int		n;
	char	c;
};

class Serializer {
private :
	Serializer();

public :
	Serializer(const Serializer& src);
	~Serializer();
	Serializer&	operator=(const Serializer& src);

	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif