#include "Harl.hpp"
#include "messages.hpp"
#include <iostream>

Harl::Harl(void) { init_lookup_table(); }

Harl::~Harl(void) {}

void Harl::debug(void) { std::cout << DEBUG << std::endl; }

void Harl::info(void) { std::cout << INFO << std::endl; }

void Harl::warning(void) { std::cout << WARNING << std::endl; }

void Harl::error(void) { std::cout << ERROR << std::endl; }

void Harl::unexpected(void) { std::cout << UNEXPECTED << std::endl; }

void Harl::complain(std::string level) { (this->*funcs[index_of(level)])(); }

void Harl::init_lookup_table(void) {
    for (int i = 0; i < TABLE_SIZE; i++)
        funcs[i] = &Harl::unexpected;
    funcs[index_of("DEBUG")] = &Harl::debug;
    funcs[index_of("INFO")] = &Harl::info;
    funcs[index_of("WARNING")] = &Harl::warning;
    funcs[index_of("ERROR")] = &Harl::error;
}

int Harl::index_of(const std::string &level) {
    int hash = 5381;
    for (int i = 0; i < (int)level.length(); ++i)
        hash = ((hash << 5) + hash) + level[i];
    return (hash & 0b11111111111 % TABLE_SIZE);
}
