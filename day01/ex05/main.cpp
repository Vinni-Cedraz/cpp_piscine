#include "Harl.hpp"
#include <iostream>

int main(void) {
    Harl harl;

    std::cout << "Default order: DEBUG -> INFO -> WARNING -> ERROR\n\n";
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    std::cout << "-----------------------------------------------------------\n";
    std::cout << "Reversed order: ERROR -> WARNING -> INFO -> DEBUG\n\n";
    harl.complain("ERROR");
    harl.complain("WARNING");
    harl.complain("INFO");
    harl.complain("DEBUG");

    std::cout << "-----------------------------------------------------------\n";
    std::cout << "RANDOM ORDER: WARNING -> DEBUG -> ERROR -> INFO\n\n";
	harl.complain("WARNING");
	harl.complain("DEBUG");
	harl.complain("ERROR");
	harl.complain("INFO");
}
