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
