#include "BitcoinExchange.hpp"
#include <sstream>

// important
BitcoinExchange::BitcoinExchange(const char *filename) {
  create_database("data.csv");
  create_input_queue(filename);
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

void BitcoinExchange::calculate_prices(void) {
  while (!input.empty()) {
    std::pair<std::string, float> price = pop_front(input);
    if (false == has_errors(price)) {
		calculate_price(price);
	}
    prices.push(price);
  }
}

bool BitcoinExchange::has_errors(std::pair<std::string, float> &price) {
  if (format_error(price) || value_error(price, price.second)) {
    return true;
  } else if (!valid_date_format(price.first)) {
    const std::string input = price.first;
    price.first = "Error: invalid date => ";
    price.first.append(input);
    return true;
  }
  return false;
}

void BitcoinExchange::calculate_price(std::pair<std::string, float> &price) {
  if (!csv[price.first]) {
    std::map<std::string, float>::iterator lower = csv.lower_bound(price.first);
    --lower;
    price.second = lower->second * price.second;
  } else {
    price.second *= csv[price.first];
  }
}

std::queue<std::pair<std::string, float> > BitcoinExchange::get_prices() { return this->prices; }

void BitcoinExchange::create_database(const char *filename) {
  std::fstream *file = open_file(filename);
  std::map<std::string, float> database;
  std::string line;
  std::getline(*file, line); // Skip the first line

  while (std::getline(*file, line)) {
    std::istringstream iss(line);
    std::string date;
    float value;

    if (line.empty())
      continue;
    std::getline(iss, date, ',');
    iss >> value;

    database[date] = value;
  }
  delete file;
  this->csv = database;
}

void BitcoinExchange::create_input_queue(const char *filename) {
  std::fstream *file = open_file(filename);
  std::string line;
  std::getline(*file, line); // Skip the first linoe

  while (std::getline(*file, line)) {
    std::istringstream iss(line);
    std::string date;
    float value;
    std::string tmp;

    if (line.empty())
      continue;
    if (!valid_line_format(line)) {
      input.push(std::make_pair(line, -42));
      continue;
    }

    std::getline(iss, date, ' ');                             // init date:
    std::getline(iss, tmp, '|'), std::getline(iss, tmp, ' '); // advance to the value:

    iss >> value;
    input.push(std::make_pair(date, value));
  }
  delete file;
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
  if (sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3)
    return false;
  if (year < 1000 || year > 9999)
    return false;
  if (month < 1 || month > 12)
    return false;
  if (day < 1 || day > 31)
    return false;
  return true;
}

bool value_error(std::pair<std::string, float> &curr_pair, const float value) {
  if (curr_pair.second != -42 && (value < 0 || value > 1000)) {
    curr_pair.first = "value out of bounds";
    return true;
  }
  return false;
}

bool format_error(std::pair<std::string, float> &curr_pair) {
  if (curr_pair.second == -42) {
    return true;
  }
  return false;
}

bool valid_line_format(const std::string line) {
  int year, month, day, value;
  if (sscanf(line.c_str(), "%4d-%2d-%2d | %d", &year, &month, &day, &value) != 4)
    return false;
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
std::ostream &operator<<(std::ostream &os, std::queue<std::pair<std::string, float> > lst) {
  while (!lst.empty()) {
    const std::pair<std::string, float> pair = BitcoinExchange::pop_front(lst);
    if (pair.first.find("Error: bad input => ") != std::string::npos)
      os << pair.first << std::endl;
    else if (pair.second == -42)
      os << "Error: invalid line: " << pair.first << std::endl;
    else if (pair.first == "value out of bounds")
      os << "Error: value too big or too small: " << pair.second << std::endl;
    else if (pair.first.find("invalid date") != std::string::npos)
      os << pair.first << std::endl;
    else
      os << pair.first << " => " << pair.second << std::endl;
  }
  return os;
}
