#pragma once
#include <string>

class ScalarConverter {
  private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &obj);
    ScalarConverter &operator=(const ScalarConverter &obj);

  public:
    static void convert(const std::string &str);
};

void convertChar(const std::string &str);
template <typename type> void convertType(const std::string &str, const std::string &name);
bool isSpecialString(std::string s);
void printSpecialString(const std::string str);
bool validInt(const std::string str);
void printNonInteger(const std::string str, double value);
