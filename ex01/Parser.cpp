#include "Parser.hpp"
#include <cstdlib>
#include <iostream>

static void show_prompt_and_get_input(prompts_and_inputs_t prompts_and_inputs);

Parser::Parser() : number_of_prompts(5) {};

void Parser::parse_input(user_input_t &final_input) {
    prompts_and_inputs_t prompts_and_inputs[] = {
        {"Enter first name: ", &final_input.first_name, RED "First name cannot be empty" RESET},
        {"Enter last name: ", &final_input.last_name, RED "Last name cannot be empty" RESET},
        {"Enter nickname: ", &final_input.nickname, RED "Nickname cannot be empty" RESET},
        {"Enter phone number: ", &final_input.phone_number, RED "Phone number cannot be empty" RESET},
        {"Enter darkest secret: ", &final_input.darkest_secret, RED "Darkest secret cannot be empty" RESET}};
    read_print_evaluate_loop(prompts_and_inputs);
}

void Parser::read_print_evaluate_loop(prompts_and_inputs_t prompts_and_inputs[]) {
    for (int i = 0; i < number_of_prompts; ++i) {
        show_prompt_and_get_input(prompts_and_inputs[i]);
        while (prompts_and_inputs[i].input->empty()) {
            std::cerr << prompts_and_inputs[i].error_message << std::endl;
            show_prompt_and_get_input(prompts_and_inputs[i]);
        }
    }
}

static void show_prompt_and_get_input(prompts_and_inputs_t prompts_and_inputs) {
    std::cout << prompts_and_inputs.prompt;
    if (!std::getline(std::cin, *prompts_and_inputs.input))
        exit(1);
}
