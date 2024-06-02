#include "PhoneBook.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() { this->idx = 0; }

void PhoneBook::clean_stdin() {
    clearerr(stdin);
    std::cin.clear();
}

void PhoneBook::add_CMD() {
    user_input_t input;
    InputValidator parser;
    parser.parse_input(input);
    this->add_contact(input);
}

void PhoneBook::add_contact(const user_input_t &perfect_input) {
    contacts[idx].setUserInput(perfect_input);
    idx = (idx + 1) % 8; // reset idx to 0 if it reaches 8
}

void PhoneBook::search_CMD() {
    int index;
    display_contacts();
    while (true) {
        std::cout << CYAN "Enter the index of the contact you want to search: " RESET;
        std::cin >> index;
        if (std::cin.eof())
            clean_stdin();
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
    if (index < 0 || index > 7 || contacts[index].getUserInput().first_name.empty()) {
        std::cerr << RED "Error: out of range index." RESET << std::endl;
        return;
    }
    std::cout << "First Name: " << contacts[index].getUserInput().first_name << std::endl;
    std::cout << "First Last Name: " << contacts[index].getUserInput().last_name << std::endl;
    std::cout << "First Nickname: " << contacts[index].getUserInput().nickname << std::endl;
    std::cout << "First Phone Number: " << contacts[index].getUserInput().phone_number << std::endl;
    std::cout << "First Darkest Secret: " << contacts[index].getUserInput().darkest_secret << std::endl;
}
