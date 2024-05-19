#include "PhoneBook.hpp"
#include <cstring>
#include <iostream>
#include <string>

PhoneBook::PhoneBook() { this->idx = 0; }

void PhoneBook::add_contact(std::string first_name, std::string last_name, std::string nickname,
                            std::string phone_number, std::string darkest_secret) {
    contacts[idx].setFirstName(first_name);
	contacts[idx].setLastName(last_name);
	contacts[idx].setNickName(nickname);
	contacts[idx].setPhoneNumber(phone_number);
	contacts[idx].setDarkestSecret(darkest_secret);
    idx = (idx + 1) % 8; // reset idx to 0 if it reaches 8
}

void PhoneBook::display_contacts(void) {
    for (int i = 0; i < 8; i++) {
        std::string first_name = contacts[i].getFirstName();
        std::string last_name = contacts[i].getLastName();
		std::string nick_name = contacts[i].getNickName();
		std::string phone_number = contacts[i].getPhoneNumber();
		std::string darkest_secret = contacts[i].getDarkestSecret();
		if (!first_name.empty())
			std::cout << "First Name: " << first_name << std::endl;
		if (!last_name.empty())
			std::cout << "Last Name: " << last_name << std::endl;
		if (!nick_name.empty())
			std::cout << "Nick Name: " << nick_name << std::endl;
		if (!phone_number.empty())
			std::cout << "Phone Number: " << phone_number << std::endl;
		if (!darkest_secret.empty())
			std::cout << "Darkest Secret: " << darkest_secret << std::endl;
    }
}
