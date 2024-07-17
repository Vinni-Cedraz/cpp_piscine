#include "ScalarConverter.hpp"
#include <climits>
#include <iostream>
#include <sstream>
#include <string>

void ScalarConverter::convert(const std::string &str) {
    std::istringstream iss(str);

    int i;
    if (iss >> i) {
        std::cout << "int: " << i << std::endl;
    } else {
        std::cout << "int: invalid" << std::endl;
    }

    iss.clear();
    iss.str(str);

    float f;
    if (iss >> f) {
        std::cout << "float: " << f << std::endl;
    } else {
        std::cout << "float: invalid" << std::endl;
    }

    iss.clear();
    iss.str(str);

    double d;
    if (iss >> d) {
        std::cout << "double: " << d << std::endl;
    } else {
        std::cout << "double: invalid" << std::endl;
    }

    if (str.length() == 1) {
        char c = str[0];
        std::cout << "char: " << c << std::endl;
    } else {
        iss.clear();
        iss.str(str);

        if (iss >> i && i >= CHAR_MIN && i <= CHAR_MAX) {
            char c = static_cast<char>(i);
            std::cout << "char: " << c << std::endl;
        } else {
            std::cout << "char: out of range" << std::endl;
        }
    }
}
