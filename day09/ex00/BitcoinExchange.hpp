#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <unistd.h>

class BitcoinExchange {
private:
  std::queue<std::pair<std::string, float> > input;
  std::map<std::string, float> csv;
  std::queue<std::pair<std::string, float> > prices;

public:
  BitcoinExchange(const char *filename);
  // <ORTHODOX CANNONICAL STUFF>
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &copy);
  BitcoinExchange &operator=(const BitcoinExchange &assign);
  ~BitcoinExchange();
  // </ORTHODOX CANNONICAL STUFF>

  void create_input_queue(const char *filename);
  void create_database(const char *filename);
  bool has_errors(std::pair<std::string, float>& price);
  void calculate_price(std::pair<std::string, float>& price);
  void calculate_prices();
  std::queue<std::pair<std::string, float> > get_prices();
  template <typename T> static T pop_front(std::queue<T> &q) {
    T front = q.front();
    q.pop();
    return front;
  }
};

std::fstream *open_file(const char *filename);
bool valid_date_format(const std::string &date);
bool value_error(std::pair<std::string, float> &pair, const float value);
bool format_error(std::pair<std::string, float> &pair);
bool valid_line_format(const std::string line);
std::ostream &operator<<(std::ostream &os, const std::map<std::string, float> &map);
std::ostream &operator<<(std::ostream &os, const std::queue<std::pair<std::string, float> > q);
