#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc > 2) {
        std::cerr << "error: the program should only receive a single argument" << std::endl;
		return 1;
    } else if (argc == 1) {
		std::cerr << "error: the program should receive an argument" << std::endl;
		return 1;
	}
    ScalarConverter::convert(argv[1]);
}
