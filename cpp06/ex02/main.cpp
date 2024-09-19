#include "Base.hpp"

int	main() {
	// Base nop;
	Base* obj = Base::generate();
	obj->identify(obj);
	obj->identify(*obj);
	delete obj;
	return 0;
}