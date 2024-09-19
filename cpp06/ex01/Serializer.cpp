#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Default Serializer constuctor called" << std::endl;
}

Serializer::Serializer(const Serializer& src) {
	std::cout << "Copy Serializer constuctor called" << std::endl;
	*this = src;
}

Serializer::~Serializer() {
	std::cout << "Serializer Destructor called" << std::endl;
}

Serializer&	Serializer::operator=(const Serializer& src) {
	std::cout << "Copy assignment Serializer operator called" << std::endl;
	(void)src;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}