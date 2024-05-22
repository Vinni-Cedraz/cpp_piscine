#include "Contact.hpp"

Contact::Contact() : perfect_input() {}

void Contact::setUserInput(const user_input_t &perfect_input) { this->perfect_input = perfect_input; }
const user_input_t Contact::getUserInput() const { return this->perfect_input; }
const std::string &Contact::getFirstName() const { return this->perfect_input.first_name; }
const std::string &Contact::getLastName() const { return this->perfect_input.last_name; }
const std::string &Contact::getNickName() const { return this->perfect_input.nickname; }
const std::string &Contact::getPhoneNumber() const { return this->perfect_input.phone_number; }
const std::string &Contact::getDarkestSecret() const { return this->perfect_input.darkest_secret; }
