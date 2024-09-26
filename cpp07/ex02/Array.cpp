#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(0) {
	std::cout << "Default Array constuctor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& src) : _size(src.size) {
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
	delete[] this->array;
	std::cout << "Array destructor called" << std::endl;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_size = src._size;
		delete[] this->_array;
		this->_array = new T[this->_size];
		for (unsigned int i = 0 ; i < this->_size ; i++)
			this->_array[i] = src._array[i];
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](int n)
{
	if (n < 0 || n >= this->_size)
		throw("Index is out of bounds");
	return (this->_array[n]);
}

template <typename T>
unsigned int	Array<T>::size() {
	return this->_size;
}