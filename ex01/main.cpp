#include <iostream>
#include "tests/test.h"

int main() {
    PhoneBook pb;
	std::cout << CYAN "WELCOME TO THE SHITTIEST PHONEBOOK OF 2024" RESET << std::endl;
	std::cout << "Your commands are ADD, SEARCH and EXIT" << std::endl;
	while (true) {
		std::string cmd;
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			pb.add_CMD();
		else if (cmd == "EXIT")
			break ;
	}
}
