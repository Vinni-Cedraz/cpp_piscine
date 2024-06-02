#include "iostream"
#include "PhoneBook.hpp"
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#define RESET "\033[0m"
#define CLEANWINDOW "\e[1;1H\e[2J"

int main() {
    PhoneBook pb;
    std::string cmd;
    std::cout << CLEANWINDOW;
    std::cout << CYAN "WELCOME TO THE SHITTIEST PHONEBOOK OF 2024" RESET << std::endl;
    std::cout << "Your commands are ADD, SEARCH and EXIT" << std::endl;
    while (true) {
        if (!std::getline(std::cin, cmd))
            pb.clean_stdin();
        else if (cmd == "EXIT")
            break;
        else if (cmd == "ADD")
            pb.add_CMD();
        else if (cmd == "SEARCH")
            pb.search_CMD();
    }
}
