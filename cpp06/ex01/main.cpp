#include "Serializer.hpp"

int	main() {
	// Serializer nop;
	Data	data;
	data.n = 42;
	data.c = '*';

	uintptr_t	raw = Serializer::serialize(&data);
	Data*		dataPtr = Serializer::deserialize(raw);

	std::cout << "data.n = " << dataPtr->n << std::endl;
	std::cout << "data.c = " << dataPtr->c << std::endl;
	return 0;
}