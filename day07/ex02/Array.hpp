#pragma once

template <typename T>
class Array {
 private:
  T *_array;
  unsigned int _size;

 public:
  Array() : _array(), _size() {}
  Array(unsigned int size) : _array(), _size(size) {
    if (size) _array = new T[size];
  }
  Array(const Array &other) { *this = Array(other._size); }
  Array &operator=(const Array &other) {
    if (this != &other) {
      _size = other._size;
      for (unsigned int i = 0; i < _size; i++) {
        _array[i] = other._array[i];
      }
    }
    return *this;
  }
};
