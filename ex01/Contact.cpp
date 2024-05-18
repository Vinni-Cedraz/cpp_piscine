#include "Contact.hpp"

Contact::Contact() : name(""), number("") {}
Contact::~Contact() {}

Contact::Contact(const std::string &name, const std::string &number) {
    this->name = name;
    this->number = number;
}

void Contact::setNameNumber(const std::string &name, const std::string &number) {
    this->name = name;
    this->number = number;
};

const std::string &Contact::getName() const { return this->name; }

const std::string &Contact::getNumber() const { return this->number; }
