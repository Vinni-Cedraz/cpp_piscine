#pragma once
#include <stdint.h>
#include <string>

class Data {
  private:
    std::string content;

  public:
    Data();
    ~Data();
    Data(const Data &src);
    Data(const std::string &content);
    Data &operator=(const Data &rhs);
	std::string getContent();
};
