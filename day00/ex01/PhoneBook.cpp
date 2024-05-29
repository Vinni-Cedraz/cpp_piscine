#include "PhoneBook.hpp"
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() {
    this->idx = 0;
    this->contacts_count = 0;
}

void PhoneBook::add_CMD() {
    user_input_t input;
    InputValidator parser;
    parser.parse_input(input);
    this->add_contact(input);
}

void PhoneBook::add_contact(const user_input_t &perfect_input) {
    contacts[idx].setUserInput(perfect_input);
    idx = (idx + 1) % 7;                                             // reset idx to 0 if it reaches 7
    contacts_count = (contacts_count == 9) ? 8 : contacts_count + 1; // reset count to 8 if it reaches 9
}

void PhoneBook::search_CMD() {
    const int last_idx = (contacts_count == 0) ? 0 : contacts_count - 1;
    int index;
    display_contacts();
    while (true) {
        std::cout << CYAN "Enter the index of the contact you want to search (0-" << last_idx << "): " RESET;
        std::cin >> index;
        if (std::cin.eof())
            exit(1);
        search_contact(index);
        break;
    }
}

static inline void output_field(const std::string contact_field) {
    if (contact_field.size() <= 10) {
        std::cout << std::setw(10) << std::right << contact_field.substr(0, 10) << std::right << " | ";
    } else {
        std::cout << std::setw(10) << std::right << contact_field.substr(0, 9) << "." << std::right << "| ";
    }
}

void PhoneBook::display_contacts(void) {
    for (int idx = 0; idx < 8; idx++) {
        const user_input_t input = contacts[idx].getUserInput();
        if (input.first_name.empty())
            break;
        std::cout << CYAN << idx << " | " RESET;
        output_field(input.first_name);
        output_field(input.last_name);
        output_field(input.nickname);
        std::cout << std::endl;
    }
}

void PhoneBook::search_contact(const int index) {
    if (index > 7 || contacts[index].getUserInput().first_name.empty()) {
        std::cerr << RED "Error: out of range index." RESET << std::endl;
        return;
    }
    std::cout << "First Name: " << contacts[index].getUserInput().first_name << std::endl;
    std::cout << "First Last Name: " << contacts[index].getUserInput().last_name << std::endl;
    std::cout << "First Nickname: " << contacts[index].getUserInput().nickname << std::endl;
    std::cout << "First Phone Number: " << contacts[index].getUserInput().phone_number << std::endl;
    std::cout << "First Darkest Secret: " << contacts[index].getUserInput().darkest_secret << std::endl;
}
