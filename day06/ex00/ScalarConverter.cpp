#include "ScalarConverter.hpp"
#include <climits>
#include <iostream>
#include <sstream>
#include <string>

void convertChar(const std::string &str);
template <typename type> void convertType(const std::string &str, const std::string &name);

void ScalarConverter::convert(const std::string &str) {
    convertType<int>(str, "int");
    convertType<float>(str, "float");
    convertType<double>(str, "double");
    convertType<char>(str, "char");
}

template <typename type> void convertType(const std::string &str, const std::string &name) {
    type value;
    std::istringstream iss(str);
    if (name == "char")
        convertChar(str);
    else if (iss >> value)
        std::cout << name << ": " << value << std::endl;
    else
        std::cout << name << ": invalid" << std::endl;
}

void convertChar(const std::string &str) {
    std::istringstream iss(str);
    int i;
    if (str.length() == 1) {
        char c = str[0];
        std::cout << "char: '" << c << "'" << std::endl;
    } else if (iss >> i && i >= CHAR_MIN && i <= CHAR_MAX) {
        char c = static_cast<char>(i);
        std::cout << "char: '" << c << '\'' << std::endl;
    } else {
        std::cout << "char: out of range" << std::endl;
    }
}
