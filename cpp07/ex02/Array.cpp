#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(0) {
	std::cout << "Default Array constuctor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& src) : _size(src.size()) {
	std::cout << "Copy Array constuctor called" << std::endl;
	this->_array = new T[this->_size];
	for (unsigned int i = 0 ; i < this->_size ; i++)
		this->_array[i] = src._array[i];
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
	std::cout << "Parametric Array constuctor called" << std::endl;
}

template <typename T>
Array<T>::~Array() {
	delete[] this->_array;
	this->_array = 0;
	std::cout << "Array destructor called" << std::endl;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_size = src.size();
		delete[] this->_array;
		this->_array = new T[this->_size];
		for (unsigned int i = 0 ; i < this->_size ; i++)
			this->_array[i] = src._array[i];
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](int n) {
	if (n < 0 || n >= static_cast<int>(this->_size))
		throw(Array::OutOfBounds());
	return (this->_array[n]);
}

template <typename T>
const T&	Array<T>::operator[](int n) const {
	if (n < 0 || n >= static_cast<int>(this->_size))
		throw(Array::OutOfBounds());
	return (this->_array[n]);
}

template <typename T>
unsigned int	Array<T>::size() const {
	return this->_size;
}


template <typename T>
const char*	Array<T>::OutOfBounds::what() const throw() {
	return "Index is out of bounds";
}