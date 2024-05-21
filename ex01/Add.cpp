#include "PhoneBook.hpp"
#include <iostream>
#define RED "\033[1;31m"
#define RESET "\033[0m"

static void init_strings(user_input_t &user_input);
static void check_for_empty(user_input_t &user_input);

void PhoneBook::add_CMD() {
	user_input_t user_input;
    init_strings(user_input);
    try {
        check_for_empty(user_input);
    } catch (const std::runtime_error &e) {
		std::cin.clear();
        std::cerr << e.what();
		std::cerr << "This contact won't be saved.\n";
		return ;
    }
    this->add_contact(user_input);
}

// static void init_strings(user_input_t &input) {
//     struct {
//         std::string prompt;
//         std::string* field;
//     } fields[] = {
//         {"Enter first name: ", &input.first_name},
//         {"Enter last name: ", &input.last_name},
//         {"Enter nickname: ", &input.nickname},
//         {"Enter phone number: ", &input.phone_number},
//         {"Enter darkest secret: ", &input.darkest_secret}
//     };
//
//     for (int i = 0; i < sizeof(fields)/sizeof(fields[0]); ++i) {
//         std::cout << fields[i].prompt;
//         if (!std::getline(std::cin, *fields[i].field)) return;
//     }
// }

static void init_strings(user_input_t &input) {
    std::cout << "Enter first name: ";
    if (!std::getline(std::cin, input.first_name)) return;
    std::cout << "Enter last name: ";
    if (!std::getline(std::cin, input.last_name)) return;
    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, input.nickname)) return;
    std::cout << "Enter phone number: ";
    if (!std::getline(std::cin, input.phone_number)) return;
    std::cout << "Enter darkest secret: ";
    if (!std::getline(std::cin, input.darkest_secret)) return;
}

static void check_for_empty(user_input_t &input) {
    if (input.first_name.empty())
        throw std::runtime_error(RED"Error, first name cannot be empty: " RESET);
    if (input.last_name.empty())
        throw std::runtime_error(RED"Error, last name cannot be empty: " RESET);
    if (input.nickname.empty())
        throw std::runtime_error(RED"Error, nickname cannot be empty: " RESET);
    if (input.phone_number.empty())
        throw std::runtime_error(RED"Error, phone number cannot be empty: " RESET);
    if (input.darkest_secret.empty())
        throw std::runtime_error(RED"Error, darkest secret cannot be empty: " RESET);
}
