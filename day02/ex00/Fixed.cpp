#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0) { std::cout << "Default constructor called" << std::endl; };

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    if (this != &fixed)
        (*this)._value = fixed._value;
};

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &fixed)
        _value = fixed._value;
    return *this;
};

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; };

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
};

void Fixed::setRawBits(int const raw) {
    std::cout << "getRawBits member function called" << std::endl;
    _value = raw;
};
