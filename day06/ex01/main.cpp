#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main () {
	Data a("content");

	uintptr_t b = Serializer::serialize(&a);
	Data *c = Serializer::deserialize(b);
	std::cout << c->getContent() << std::endl;
}
