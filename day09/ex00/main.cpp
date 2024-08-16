#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char**argv)
{
	if (argc < 2) {
		errorln("Error: could not open file.");
		return (0);
	}
	else if (argc > 2) {
		errorln("Error: too many arguments.");
		println(CYAN << "Usage: ./btc input.txt");
	}

	BitcoinExchange	exchange;
	
	exchange.runExchange(argv[1]);
	return (0);
}
