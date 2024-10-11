#include <sstream>

#include "BitcoinExchange.hpp"

// important
BitcoinExchange::BitcoinExchange(const char *filename) {
  create_database("data.csv");
  create_input_list(filename);
}

// useless cannonical stuff:
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) { *this = copy; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &assign) {
  if (this != &assign) {
    this->input = assign.input;
    this->csv = assign.csv;
    this->prices = assign.prices;
  }
  return *this;
}

// main logic:
void BitcoinExchange::calculate_prices(void) {
  std::list<std::pair<std::string, float> >::iterator out_it = prices.begin();

  for (std::list<std::pair<std::string, float> >::iterator in_it = input.begin(); in_it != input.end(); in_it++) {
    out_it = prices.insert(out_it, *in_it);
    // parsing
    if (value_error(out_it, in_it->second) || format_error(out_it)) {
      out_it++;
      continue;
    } else if (!csv[in_it->first]) {
      if (!valid_date_format(out_it->first)) {
        out_it->first = "Error: bad input => ";
        out_it->first.append(in_it->first);
      } else {
        std::map<std::string, float>::iterator lower = csv.lower_bound(out_it->first);
        --lower;
        out_it->second = lower->second * in_it->second;
      }
      out_it++;
      continue;
    }
    // standard operation
    out_it->second = csv[in_it->first] * in_it->second;
    out_it++;
  }
}

std::list<std::pair<std::string, float> > BitcoinExchange::get_prices() { return this->prices; }

void BitcoinExchange::create_database(const char *filename) {
  std::fstream *file = open_file(filename);
  std::map<std::string, float> database;
  std::string line;
  std::getline(*file, line);  // Skip the first line

  while (std::getline(*file, line)) {
    std::istringstream iss(line);
    std::string date;
    float value;

    if (line.empty()) continue;
    std::getline(iss, date, ',');
    iss >> value;

    database[date] = value;
  }
  delete file;
  this->csv = database;
}

void BitcoinExchange::create_input_list(const char *filename) {
  std::fstream *file = open_file(filename);
  std::list<std::pair<std::string, float> > input_list;
  std::string line;
  std::getline(*file, line);  // Skip the first linoe

  while (std::getline(*file, line)) {
    std::istringstream iss(line);
    std::string date;
    float value;
    std::string tmp;

    if (line.empty()) continue;
    if (!valid_line_format(line)) {
      input_list.push_back(std::make_pair(line, -42));
      continue;
    }

    std::getline(iss, date, ' ');                              // init date:
    std::getline(iss, tmp, '|'), std::getline(iss, tmp, ' ');  // advance to the value:

    iss >> value;
    input_list.push_back(std::make_pair(date, value));
  }
  delete file;
  this->input = input_list;
}

std::fstream *open_file(const char *filename) {
  std::fstream *file = new std::fstream;
  file->open(filename, std::ios::in);
  if (!*file) {
    std::cerr << "Error: Unable to open file :" << filename << std::endl;
    exit(1);
  }
  return file;
}

bool valid_date_format(const std::string &date) {
  int year, month, day;
  if (sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3) return false;
  if (year < 1000 || year > 9999) return false;
  if (month < 1 || month > 12) return false;
  if (day < 1 || day > 31) return false;
  return true;
}

bool value_error(std::list<std::pair<std::string, float> >::iterator &it, const int value) {
  if (value < 0 || value > 1000) {
    it->first = "value out of bounds";
    return true;
  }
  return false;
}

bool format_error(std::list<std::pair<std::string, float> >::const_iterator it) {
  if (it->second == -42) {
    return true;
  }
  return false;
}

bool valid_line_format(const std::string line) {
  int year, month, day, value;
  if (sscanf(line.c_str(), "%4d-%2d-%2d | %d", &year, &month, &day, &value) != 4) return false;
  return true;
}

// For debugging purposes:
std::ostream &operator<<(std::ostream &os, const std::map<std::string, float> &map) {
  for (std::map<std::string, float>::const_iterator it = map.begin(); it != map.end(); ++it) {
    os << it->first << " => " << it->second << std::endl;
  }
  return os;
}

// essential to the program:
std::ostream &operator<<(std::ostream &os, const std::list<std::pair<std::string, float> > &lst) {
  for (std::list<std::pair<std::string, float> >::const_iterator it = lst.begin(); it != lst.end(); ++it) {
    if (it->first.find("Error: bad input => ") != std::string::npos)
      os << it->first << std::endl;
    else if (it->second == -42)
      os << "Error: invalid line: " << it->first << std::endl;
    else if (it->first == "value out of bounds")
      os << "Error: value too big or too small: " << it->second << std::endl;
    else
      os << it->first << " => " << it->second << std::endl;
  }
  return os;
}
