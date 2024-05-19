#include "PhoneBook.hpp"
#include <iostream>
#define RED "\033[1;31m"
#define RESET "\033[0m"

static void init_strings(std::string &first_name, std::string &last_name, std::string &nickname,
                         std::string &phone_number, std::string &darkest_secret);
static void check_for_empty(std::string &first_name, std::string &last_name, std::string &nickname,
                            std::string &phone_number, std::string &darkest_secret);

void PhoneBook::add_CMD() {
    std::string first_name, last_name, nickname, phone_number, darkest_secret;
    init_strings(first_name, last_name, nickname, phone_number, darkest_secret);
    try {
        check_for_empty(first_name, last_name, nickname, phone_number, darkest_secret);
    } catch (const std::runtime_error &e) {
        std::cerr << e.what();
		std::cerr << "This contact won't be saved.\n";
        return;
    }
    this->add_contact(first_name, last_name, nickname, phone_number, darkest_secret);
}

static void init_strings(std::string &first_name, std::string &last_name, std::string &nickname,
                         std::string &phone_number, std::string &darkest_secret) {
    std::cout << "Enter first name: ";
    std::getline(std::cin, first_name);
    std::cout << "Enter last name: ";
    std::getline(std::cin, last_name);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone_number);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkest_secret);
}

static void check_for_empty(std::string &first_name, std::string &last_name, std::string &nickname,
                            std::string &phone_number, std::string &darkest_secret) {
    if (first_name.empty())
        throw std::runtime_error(RED"Error, first name cannot be empty: " RESET);
    if (last_name.empty())
        throw std::runtime_error(RED"Error, last name cannot be empty: " RESET);
    if (nickname.empty())
        throw std::runtime_error(RED"Error, nickname cannot be empty: " RESET);
    if (phone_number.empty())
        throw std::runtime_error(RED"Error, phone number cannot be empty: " RESET);
    if (darkest_secret.empty())
        throw std::runtime_error(RED"Error, darkest secret cannot be empty: " RESET);
}
