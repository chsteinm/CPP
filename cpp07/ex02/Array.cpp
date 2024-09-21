#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(nullptr) {
	std::cout << "Default Array constuctor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& src) {
	std::cout << "Copy Array constuctor called" << std::endl;
	*this = src;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
	std::cout << "Parametric Array constuctor called" << std::endl;
}

template <typename T>
Array<T>::~Array() {
	if (this->array)
		delete[] this->array;
	std::cout << "Array destructor called" << std::endl;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

template <typename T>
unsigned int	Array<T>::size() {

}