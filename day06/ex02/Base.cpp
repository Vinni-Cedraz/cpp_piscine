#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {}

Base *generate(void) {
    static bool first = true;
    if (first) {
        first = false;
        srand(time(0));
    }
    switch (rand() % 3) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default: return NULL;
    }
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p) {
	if (isA(p))
		std::cout << "A" << std::endl;
	else if (isB(p))
		std::cout << "B" << std::endl;
	else if (isC(p))
		std::cout << "C" << std::endl;
}
