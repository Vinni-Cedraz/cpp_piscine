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

Fixed::Fixed(const float float_value) : _value(roundf(float_value * (1 << _fractional_bits))) {
    std::cout << "float constructor called" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; };

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
};

float Fixed::toFloat(void) const { return (float)_value / (1 << _fractional_bits); };

int Fixed::toInt(void) const { return (_value >> _fractional_bits); };

void Fixed::setRawBits(int const raw) {
    std::cout << "getRawBits member function called" << std::endl;
    _value = raw;
};

std::ostream &operator<<(std::ostream &outstream, const Fixed &fixed) {
    outstream << fixed.toFloat();
    return outstream;
};

// Overloaded comparison operators
bool Fixed::operator>(const Fixed &rhs) const { return _value > rhs._value; }
bool Fixed::operator<(const Fixed &rhs) const { return _value < rhs._value; }
bool Fixed::operator>=(const Fixed &rhs) const { return _value >= rhs._value; }
bool Fixed::operator<=(const Fixed &rhs) const { return _value <= rhs._value; }
bool Fixed::operator==(const Fixed &rhs) const { return _value == rhs._value; }
bool Fixed::operator!=(const Fixed &rhs) const { return _value != rhs._value; }

// Overloaded arithmetic operators
Fixed Fixed::operator+(const Fixed &rhs) const { return Fixed(toFloat() + rhs.toFloat()); }
Fixed Fixed::operator-(const Fixed &rhs) const { return Fixed(toFloat() - rhs.toFloat()); }
Fixed Fixed::operator*(const Fixed &rhs) const { return Fixed(toFloat() * rhs.toFloat()); }
Fixed Fixed::operator/(const Fixed &r) const { return (r.toFloat() != 0) ? Fixed(toFloat() / r.toFloat()) : Fixed(0); }

// Overloaded increment/decrement operators
// Pre-increment
Fixed &Fixed::operator++() {
    _value++;
    return *this;
}
// Post-increment
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    operator++();
    return temp;
}
// Pre-decrement
Fixed &Fixed::operator--() {
    _value--;
    return *this;
}
// Post-decrement
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    operator--();
    return temp;
}

// Static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return (a < b) ? a : b; }
Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return (a > b) ? a : b; }
