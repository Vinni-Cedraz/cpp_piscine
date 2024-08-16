#include "BitcoinExchange.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange(void) {
  std::cout << "BitcoinExchange class default constructor called." << std::endl;
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &BitcoinExchange) {
  std::cout << "BitcoinExchange class copy constructor called." << std::endl;
  *this = BitcoinExchange;
};

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  std::cout << "BitcoinExchange class copy assign operator called." << std::endl;
  if (this != &rhs) {
    *this = rhs;
  }
  return *this;
};

BitcoinExchange::~BitcoinExchange(void) { std::cout << "BitcoinExchange class destructor called." << std::endl; };

void BitcoinExchange::_findNearMatch(std::string line) {
  std::stringstream ss(line);
  std::string timeStamp;
  std::string amount;
  double dAmount;

  if (std::getline(ss, timeStamp, '|') && std::getline(ss, amount)) {
    timeStamp.erase(timeStamp.length() - 1);
    std::stringstream dSSAmount(amount);
    dSSAmount >> dAmount;
    if (dSSAmount.fail())
      errorln("Error: " << amount << " is not a valid number.");
  }
  std::map<std::string, double>::iterator iter = this->_btcDb.find(timeStamp);
  if (iter != this->_btcDb.end()) {
    println(GREEN << timeStamp << " => " << dAmount << " = " << dAmount * iter->second);
  } else {
    std::map<std::string, double>::iterator rIter = this->_btcDb.end();
    rIter--;
    std::cout << std::fixed;
    std::cout.precision(2);
    while (rIter != this->_btcDb.begin()) {
      if (timeStamp < rIter->first) {
        rIter--;
      } else {
        println(GREEN << timeStamp << " => " << dAmount << " = " << dAmount * rIter->second);
        return;
      }
    };
  }
}

void BitcoinExchange::_validateAmount(std::string line) {
  size_t pos;
  double value;

  pos = line.find("|");
  value = std::atof(line.substr(pos + 2).c_str());
  if (value < 0) {
    errorln("Error: not a positive number.");
  } else if (value >= 1000) {
    errorln("Error: too large a number.");
  } else {
    this->_findNearMatch(line);
  }
};

void BitcoinExchange::_timestampChecker(std::string line) {
  std::string timestamp = line.substr(0, 10);
  std::string baseDate = "2009-01-02";

  if (timestamp < baseDate || timestamp.length() != 10 || std::count(timestamp.begin(), timestamp.end(), '-') != 2 ||
      atoi(timestamp.substr(5, 2).c_str()) > 12 || atoi(timestamp.substr(8, 2).c_str()) > 31) {
    std::cerr << RED << "Error: bad input => ";
    errorln(line);
  } else {
    this->_validateAmount(line);
  }
};

void BitcoinExchange::_formatChecker(std::string line) {
  if (line.find("|") == std::string::npos) {
    std::cerr << RED << "Error: bad input => ";
    errorln(line);
  } else {
    this->_timestampChecker(line);
  }
};

void BitcoinExchange::_inputExecutor(void) {
  std::string buffer;

  std::getline(this->_inputFile, buffer);
  while (std::getline(this->_inputFile, buffer)) {
    this->_formatChecker(buffer);
  }
};

void BitcoinExchange::_initDb(void) {
  std::ifstream csvFile;
  std::string test;

  csvFile.open("data.csv");
  while (std::getline(csvFile, test)) {
    std::istringstream iss(test);
    std::string date;
    std::string amount;

    if (std::getline(iss, date, ',') && std::getline(iss, amount)) {
      double dAmount;
      std::stringstream valueStream(amount);
      valueStream >> dAmount;
      if (!valueStream.fail())
        this->_btcDb[date] = dAmount;
    }
  }
  csvFile.close();
}

void BitcoinExchange::_inputValidator(char *inputPath) {
  std::ifstream inputFile;

  inputFile.open(inputPath);
  if (inputFile.fail())
    throw FilePathNotFoundException();
  this->_inputFile.open(inputPath);
};

void BitcoinExchange::runExchange(char *inputPath) {
  try {
    this->_inputValidator(inputPath);
    this->_initDb();
    this->_inputExecutor();

  } catch (BitcoinExchange::FilePathNotFoundException &e) {
    errorln(e.what());
    return;
  }
};

const char *BitcoinExchange::FilePathNotFoundException::what() const throw() {
  return ("Fail opening the file, path not found.");
};
