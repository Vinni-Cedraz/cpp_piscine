#include "Contact.hpp"

Contact::Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

const std::string &Contact::getFirstName() const { return this->first_name; }
const std::string &Contact::getLastName() const { return this->last_name; }
const std::string &Contact::getNickName() const { return this->nickname; }
const std::string &Contact::getPhoneNumber() const { return this->phone_number; }
const std::string &Contact::getDarkestSecret() const { return this->darkest_secret; }

void Contact::setFirstName(std::string first_name) { this->first_name = first_name; }
void Contact::setLastName(std::string last_name) { this->last_name = last_name; }
void Contact::setNickName(std::string nickname) { this->nickname = nickname; }
void Contact::setPhoneNumber(std::string phone_number) { this->phone_number = phone_number; }
void Contact::setDarkestSecret(std::string darkest_secret) { this->darkest_secret = darkest_secret; }
