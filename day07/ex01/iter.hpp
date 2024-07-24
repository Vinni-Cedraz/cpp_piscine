#pragma once
#include <iostream>

template <typename type>
void print(type &var) {
  std::cout << var << std::endl;
}

template <typename type, typename function>
void iter(type array[], unsigned int len, function func) {
  for (unsigned int i = 0; i < len; i++) func(array[i]);
}
