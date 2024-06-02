#include "Contact.hpp"

Contact::Contact() : complete_input() {}

void Contact::setUserInput(const user_input_t &complete_input) { this->complete_input = complete_input; }

const user_input_t Contact::getUserInput() const { return this->complete_input; }
const std::string &Contact::getFirstName() const { return this->complete_input.first_name; }
const std::string &Contact::getLastName() const { return this->complete_input.last_name; }
const std::string &Contact::getNickName() const { return this->complete_input.nickname; }
const std::string &Contact::getPhoneNumber() const { return this->complete_input.phone_number; }
const std::string &Contact::getDarkestSecret() const { return this->complete_input.darkest_secret; }

void Contact::cleanContactData(std::string &str) {
    InputValidator validator;
    if (!str.empty()) {
        validator.removeConsecutiveSpaces(str);
        validator.removeOuterSpaces(str);
    }
}

