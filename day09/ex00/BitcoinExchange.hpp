#pragma once

#include <unistd.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <ostream>

class BitcoinExchange {
 private:
  std::list<std::pair<std::string, float> > input;
  std::map<std::string, float> csv;
  std::list<std::pair<std::string, float> > prices;

 public:
  BitcoinExchange(const char *filename);
  // <ORTHODOX CANNONICAL STUFF>
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &copy);
  BitcoinExchange &operator=(const BitcoinExchange &assign);
  ~BitcoinExchange();
  // </ORTHODOX CANNONICAL STUFF>
  

  void create_input_list(const char *filename);
  void create_database(const char *filename);
  void calculate_prices();
  std::list<std::pair<std::string, float> > get_prices();
};

std::fstream *open_file(const char *filename);
bool valid_date_format(const std::string &date);
bool value_error(std::list<std::pair<std::string, float> >::iterator &it, const int value);
bool format_error(std::list<std::pair<std::string, float> >::const_iterator it);
bool valid_line_format(const std::string line);
std::ostream &operator<<(std::ostream &os, const std::map<std::string, float> &map);
std::ostream &operator<<(std::ostream &os, const std::list<std::pair<std::string, float> > &lst);
