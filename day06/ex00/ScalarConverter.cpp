#include "ScalarConverter.hpp"
#include <climits>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <iomanip>

void ScalarConverter::convert(const std::string &str) {
    if (false == validInt(str) || (isSpecialString(str)))
        return;
    convertType<char>(str, "char");
    convertType<int>(str, "int");
    std::cout << std::fixed << std::setprecision(7);
    convertType<float>(str, "float");
    std::cout << std::fixed << std::setprecision(15);
    convertType<double>(str, "double");
}

template <typename type> void convertType(const std::string &str, const std::string &name) {
    type value;
    std::istringstream iss(str);
    if (name == "char")
        convertChar(str);
    else if (iss >> value) {
        if (name == "float" || name == "double")
            printNonInteger(name, value);
        else
            std::cout << name << ": " << value << std::endl;
    } else
        std::cout << name << ": invalid" << std::endl;
}

void convertChar(const std::string &str) {
    std::istringstream iss(str);
    int i;
    if (false == isprint(std::atoi(str.c_str())))
        std::cout << "char: Non displayable" << std::endl;
    else if (str.length() == 1)
        std::cout << "char: '" << str << "'" << std::endl;
    else if (iss >> i)
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: invalid" << std::endl;
}

bool isSpecialString(const std::string s) {
    if (s == "nan" || s == "nanf" || s == "-inf" || s == "+inf" || s == "-inff" || s == "+inff") {
        printSpecialString(s);
        return true;
    } else
        return false;
}

void printSpecialString(const std::string str) {
    if (str == "nan")
        std::cout << "char: impossible" << std::endl
                  << "int: impossible" << std::endl
                  << "float: " << str + "f" << std::endl
                  << "double: " << str << std::endl;
    else
        std::cout << "char: impossible" << std::endl
                  << "int: impossible" << std::endl
                  << "float: " << str << std::endl
                  << "double: " << str << std::endl;
}

bool validInt(const std::string str) {
    if (std::atol(str.c_str()) > std::numeric_limits<int>::max() || std::atol(str.c_str()) < std::numeric_limits<int>::min())
        return false;
    else
        return true;
}

void printNonInteger(const std::string name, double value) {
    if (value - static_cast<int>(value) == 0) {
        if (name == "float")
            std::cout << name << ": " << value << ".0f" << std::endl;
        else
            std::cout << name << ": " << value << ".0" << std::endl;
    } else if (name == "float")
        std::cout << name << ": " << value << "f" << std::endl;
    else
        std::cout << name << ": " << value << std::endl;
}
