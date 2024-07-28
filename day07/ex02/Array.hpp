#pragma once
#include <exception>

template <typename T> class Array {
private:
  T *_array;
  unsigned int _size;

public:
  // constructors:
  Array() : _array(), _size() {}
  Array(unsigned int size) : _array(), _size(size) {
    if (size)
      _array = new T[size];
  }
  Array(const Array &other) : _array(), _size(other._size) {
    if (this != &other && _size) {
      *this = other;
    }
  }
  // operators:
  Array &operator=(const Array &other) {
	this->~Array();
	new(this) Array(other._size);
    for (unsigned int i = 0; i < _size; i++) {
      _array[i] = other._array[i];
    }
    return *this;
  }
  // exceptions:
  class OutOfLimits : public std::exception {
    const char *what() const throw() { return "Out of limits"; }
  };
  // operators:
  T &operator[](unsigned int index) {
    if (index >= _size)
      throw OutOfLimits();
    return _array[index];
  }
  // methods:
  unsigned int size() const { return _size; }
  // destructor:
  ~Array() { delete[] _array; }
};
