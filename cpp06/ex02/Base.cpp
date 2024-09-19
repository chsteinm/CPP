#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base() {
	std::cout << "Default Base constuctor called" << std::endl;
}

Base::Base(const Base& src) {
	std::cout << "Copy Base constuctor called" << std::endl;
	*this = src;
}

Base::~Base() {
	std::cout << "Base Destructor called" << std::endl;
}

Base&	Base::operator=(const Base& src) {
	std::cout << "Copy assignment Base operator called" << std::endl;
	(void)src;
	return *this;
}

Base*	Base::generate() {
	std::srand(std::time(0));
	int randomValue = std::rand() % 3;
    switch (randomValue) {
        case 0:
			std::cout << "A created\n";
            return new A();
        case 1:
			std::cout << "B created\n";
            return new B();
        case 2:
			std::cout << "C created\n";
            return new C();
        default:
            return NULL;
    }
}

void	Base::identify(Base* p) {
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
}

void	Base::identify(Base& p) {
	 try {
        A& a = dynamic_cast<A&>(p);
		(void)a;
        std::cout << "Instance of A\n";
    } catch (...) {
        try {
            B& b = dynamic_cast<B&>(p);
			(void)b;
            std::cout << "Instance of B\n";
        } catch (...) {
            try {
                C& c = dynamic_cast<C&>(p);
				(void)c;
                std::cout << "Instance of C\n";
            } catch (...) {
                std::cout << "Unknown instance\n";
            }
        }
    }
}