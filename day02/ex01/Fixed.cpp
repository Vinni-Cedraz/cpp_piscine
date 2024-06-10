#include "Fixed.hpp"
#include <cmath>
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

Fixed::Fixed(const int value) : _value(value << _fractional_bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractional_bits))) {
	std::cout << "float constructor called" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; };

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
};

float Fixed::toFloat(void) const { return ((float)_value / (1 << _fractional_bits)); };

int Fixed::toInt(void) const { return (_value >> _fractional_bits); };

void Fixed::setRawBits(int const raw) {
    std::cout << "getRawBits member function called" << std::endl;
    _value = raw;
};

std::ostream &operator<<(std::ostream &outstream, const Fixed &fixed) {
    outstream << fixed.toFloat();
    return outstream;
};
