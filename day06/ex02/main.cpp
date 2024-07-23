#include "Base.hpp"
#include <iostream>
#define cyan "\033[36m"
#define yellow "\033[33m"
#define reset "\033[0m"

int main(void)
{
	for (int i = 0; i < 10; i++) {
		Base* base = generate();

		std::cout << "test " << i <<":" << cyan <<  " identify(Base*): " << reset << std::endl;
		identify(base);
		std::cout <<  "test " << i <<":" <<  yellow << " identify(Base&): " << reset << std::endl;
		identify(*base);

		delete base;
		std::endl(std::cout);
	}

	identify(NULL);
}
