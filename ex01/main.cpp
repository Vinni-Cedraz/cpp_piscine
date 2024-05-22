#include "iostream"
#include "tests/test.h"
#include <cstdlib>
#include <unistd.h>
#define CLEANWINDOW "\e[1;1H\e[2J"

int main() {
    PhoneBook pb;
    std::string cmd;
    std::cout << CLEANWINDOW;
    std::cout << CYAN "WELCOME TO THE SHITTIEST PHONEBOOK OF 2024" RESET << std::endl;
    std::cout << "Your commands are ADD, SEARCH and EXIT" << std::endl;
    while (true) {
        if (!std::getline(std::cin, cmd))
            exit(1);
        else if (cmd == "EXIT")
            break;
        else if (cmd == "ADD")
            pb.add_CMD();
        else if (cmd == "DISPLAY")
            pb.display_contacts();
    }
}
