#include "iostream"
#include "tests/test.h"
#include <unistd.h>
#define CLEANWINDOW "\e[1;1H\e[2J"

int main() {
    PhoneBook pb;
    std::string cmd;
	std::cout << CLEANWINDOW;
    std::cout << CYAN "WELCOME TO THE SHITTIEST PHONEBOOK OF 2024" RESET << std::endl;
    std::cout << "Your commands are ADD, SEARCH and EXIT" << std::endl;
    char buffer[1024];
    while (true) {
        ssize_t len = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
        if (len > 0) {
            buffer[len] = '\0';
            cmd = buffer;
            if (cmd == "EXIT\n")
                break;
            if (cmd == "ADD\n")
                pb.add_CMD();
            else if (cmd == "DISPLAY\n")
                pb.display_contacts();
        } else if (len <= 0) {
			cmd.clear();
            continue;
        }
    }
}
