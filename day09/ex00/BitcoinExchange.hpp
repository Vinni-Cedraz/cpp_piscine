#pragma once
#include <cstdlib>
#include <exception>
#include <fstream>
#include <map>
#include <string>

#define println(x) std::cout << x << DFT << std::endl;
#define printlnnl(x) std::cout << x << DFT << "\n" << std::endl;
#define errorln(x) std::cerr << RED << x << DFT << std::endl;

#define BLUE_GREEN "\033[32;44m"
#define MAG_YE "\033[33;45m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
#define ORANGE "\033[0;38;5;166m"
#define GRAY "\033[38;5;244m"
#define DFT "\033[0m"

class BitcoinExchange {

public:
  BitcoinExchange(void);
  ~BitcoinExchange(void);
  void runExchange(char *inputPath);

private:
  BitcoinExchange(const BitcoinExchange &BitcoinExchange);
  BitcoinExchange &operator=(const BitcoinExchange &rhs);

  std::map<std::string, double> _btcDb;
  std::ifstream _inputFile;

  void _inputValidator(char *inputPath);
  void _initDb(void);
  void _inputExecutor(void);
  void _formatChecker(std::string line);
  void _timestampChecker(std::string line);
  void _validateAmount(std::string line);
  void _findNearMatch(std::string line);

  class FilePathNotFoundException : std::exception {
  public:
    virtual const char *what() const throw();
  };
};
