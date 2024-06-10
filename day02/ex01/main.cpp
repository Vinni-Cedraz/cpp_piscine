#include "Fixed.hpp"
#include <iostream>

#define OUT(x, y) std::cout << x << y << std::endl

int main(void) {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);
    OUT("a is ", a);
    OUT("b is ", b);
    OUT("c is ", c);
    OUT("d is ", d);
    OUT("a as Int is ", a.toInt());
    OUT("b as Int is ", b.toInt());
    OUT("c as Int is ", c.toInt());
    OUT("d as Int is ", d.toInt());
}
