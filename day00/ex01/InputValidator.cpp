#include "InputValidator.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>

static void show_prompt_and_get_input(prompts_t prompts);

InputValidator::InputValidator() : number_of_prompts(5) {};

void InputValidator::parse_input(user_input_t &final_input) {
    prompts_t prompts[] = {
        {"Enter first name: ", &final_input.first_name, RED "First name cannot be empty" RESET},
        {"Enter last name: ", &final_input.last_name, RED "Last name cannot be empty" RESET},
        {"Enter nickname: ", &final_input.nickname, RED "Nickname cannot be empty" RESET},
        {"Enter phone number: ", &final_input.phone_number, RED "Phone number cannot be empty" RESET},
        {"Enter darkest secret: ", &final_input.darkest_secret, RED "Darkest secret cannot be empty" RESET}};
    read_print_evaluate_loop(prompts);
}

void InputValidator::read_print_evaluate_loop(prompts_t prompts[]) {
    for (int i = 0; i < number_of_prompts; ++i) {
        show_prompt_and_get_input(prompts[i]);
        while (prompts[i].input->empty()) {
            show_prompt_and_get_input(prompts[i]);
        }
    }
}

static void show_prompt_and_get_input(prompts_t prompts) {
    std::cout << prompts.prompt;
    if (!std::getline(std::cin, *prompts.input)) {
        std::cerr << prompts.error_message << std::endl;
        clearerr(stdin);
        std::cin.clear();
    }
}

bool InputValidator::doesntHaveLetters(std::string phone_number) {
    for (std::size_t index = 0; index < phone_number.length(); ++index) {
        if (!std::isdigit(phone_number[index]) && phone_number[index] != '+') {
            std::cerr << RED "Invalid phone number" RESET << std::endl;
            phone_number.clear();
            return (false);
        }
    }
    return (true);
}

void InputValidator::removeConsecutiveSpaces(std::string &str) {
    int size;

    size = str.length();
    for (int i = 0; i < size; i++) {
        if ((str[i] == ' ' || str[i] == '\t') && (str[i + 1] == ' ' || str[i + 1] == '\t')) {
            str.erase(i, 1);
            size = str.length();
            i = 0;
        }
    }
}

void InputValidator::removeOuterSpaces(std::string &str) {
    int size;

    size = str.length();
    while (size > 0 && (str[size - 1] == ' ' || str[size - 1] == '\t')) {
        str.erase(size - 1, 1);
        size = str.length();
    }
    while (size > 0 && (str[0] == ' ' || str[0] == '\t')) {
        str.erase(0, 1);
        size = str.length();
    }
}
