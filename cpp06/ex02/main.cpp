#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate() {
	std::srand(std::time(0));
	int randomValue = std::rand() % 3;
    switch (randomValue) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void	identify(Base* p) {
A* a = dynamic_cast<A*>(p);
if (a){
	std::cout << "The actual type of the object pointed to by p is : A" << std::endl;
	return ;
}
B* b = dynamic_cast<B*>(p);
if (b){
	std::cout << "The actual type of the object pointed to by p is : B" << std::endl;
	return ;
}
C* c = dynamic_cast<C*>(p);
if (c){
	std::cout << "The actual type of the object pointed to by p is : C" << std::endl;
	return ;
}
std::cout << "Unknown instance" << std::endl;
}

void	identify(Base& p) {
	 try {
        A& a = dynamic_cast<A&>(p);
		(void)a;
        std::cout << "The actual type of the object pointed to by p is : A" << std::endl;
    } catch (...) {
        try {
            B& b = dynamic_cast<B&>(p);
			(void)b;
            std::cout << "The actual type of the object pointed to by p is : B" << std::endl;
        } catch (...) {
            try {
                C& c = dynamic_cast<C&>(p);
				(void)c;
                std::cout << "The actual type of the object pointed to by p is : C" << std::endl;
            } catch (...) {
                std::cout << "Unknown instance" << std::endl;
            }
        }
    }
}

int	main() {
	// Base nop;
	Base* obj = generate();
	identify(obj);
	identify(*obj);
	delete obj;
	return 0;
}