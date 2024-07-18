#include "Data.hpp"

Data::Data() : content("default") {};

Data::~Data() {};

Data::Data(const Data &src) { *this = src; }

Data::Data(const std::string &content) { this->content = content; }

Data &Data::operator=(Data const &rhs) {
    content = rhs.content;
    return *this;
}

std::string Data::getContent() { return content; }
