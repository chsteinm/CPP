#include "Serializer.hpp"

int	main() {
	// Serializer nop;
	Data	data;
	Data*	ptr = &data;
	data.n = 42;
	data.c = '*';

	std::cout << "data.n = " << data.n << std::endl;
	std::cout << "data.c = " << data.c << std::endl << std::endl;

	uintptr_t	raw = Serializer::serialize(&data);
	Data*		dataPtr = Serializer::deserialize(raw);

	std::cout << "dataPtr.n = " << dataPtr->n << std::endl;
	std::cout << "dataPtr.c = " << dataPtr->c << std::endl << std::endl;

	if (ptr == dataPtr)
		std::cout << "ptr == dataPtr" << std::endl;
	else
		std::cout << "ptr != dataPtr" << std::endl;

	return 0;
}