#include "FixedPointNumber.hpp"
#include <iostream>

FixedPointNumber::FixedPointNumber() : _value(0) { std::cout << "Default constructor called" << std::endl; };

FixedPointNumber::FixedPointNumber(const FixedPointNumber &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    if (this != &fixed)
        (*this)._value = fixed._value;
};

FixedPointNumber &FixedPointNumber::operator=(const FixedPointNumber &fixed) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &fixed)
        _value = fixed._value;
    return *this;
};

FixedPointNumber::~FixedPointNumber() { std::cout << "Destructor called" << std::endl; };

int FixedPointNumber::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
};

void FixedPointNumber::setRawBits(int const raw) {
    std::cout << "getRawBits member function called" << std::endl;
    _value = raw;
};
