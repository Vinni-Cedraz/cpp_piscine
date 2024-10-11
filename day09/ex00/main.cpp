#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Error: missing input argument." << std::endl;
    return (1);
  } else if (argc > 2) {
    std::cout << "Error: too many arguments." << std::endl;
    std::cout << "Usage: ./btc input.txt" << std::endl;
    return (1);
  }
  (void)argv;

  BitcoinExchange exchange(argv[1]);

  exchange.calculate_prices();
  std::cout << "prices: " << std::endl << exchange.get_prices() << std::endl;
}
