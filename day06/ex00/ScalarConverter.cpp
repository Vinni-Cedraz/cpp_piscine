#include "ScalarConverter.hpp"
#include <climits>
#include <iostream>
#include <sstream>
#include <string>

void convertInt(const std::string &str) {
    int i;
    std::istringstream iss(str);

    if (iss >> i)
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: invalid" << std::endl;
}

void convertFloat(const std::string &str) {
    float f;
    std::istringstream iss(str);
    if (iss >> f)
        std::cout << "float: " << f << std::endl;
    else
        std::cout << "float: invalid" << std::endl;
}

void convertDouble(const std::string &str) {
    double d;
    std::istringstream iss(str);
    if (iss >> d)
        std::cout << "float: " << d << std::endl;
    else
        std::cout << "float: invalid" << std::endl;
}

void convertChar(const std::string &str) {
    std::istringstream iss(str);
    int i;
    if (str.length() == 1) {
        char c = str[0];
        std::cout << "char: '" << c << "'" << std::endl;
    } else {
        iss.clear();
        iss.str(str);

        if (iss >> i && i >= CHAR_MIN && i <= CHAR_MAX) {
            char c = static_cast<char>(i);
            std::cout << "char: '" << c << '\''<< std::endl;
        } else {
            std::cout << "char: out of range" << std::endl;
        }
    }
}

void ScalarConverter::convert(const std::string &str) {
    convertInt(str);
    convertFloat(str);
    convertDouble(str);
	convertChar(str);
}
