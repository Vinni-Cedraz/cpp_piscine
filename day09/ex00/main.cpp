#include "BitcoinExchange.hpp"

static std::fstream *open_file(const char *filename) {
  std::fstream *file = new std::fstream;
  file->open(filename, std::ios::in);
  if (!*file) {
    std::cerr << "Error: Unable to open file :" << filename << std::endl;
    exit(1);
  }
  return file;
}

static std::map<std::string, float> create_database(const char *filename) {
  std::fstream *file = open_file(filename);
  std::map<std::string, float> database;
  std::string line;
  // Skip the first line
  std::getline(*file, line);

  while (std::getline(*file, line)) {
    std::istringstream iss(line);
    std::string date;
    float value;

    // Try to read the date
    std::getline(iss, date, ',');

    // Try to read the value
    iss >> value;

    // Add the date and value to the map
    database[date] = value;
  }
  delete file;
  return database;
}

static std::list<std::pair<std::string, float> > create_database_list(const char *filename) {
  std::fstream *file = open_file(filename);
  std::list<std::pair<std::string, float> > database;
  std::string line;
  // Skip the first line
  std::getline(*file, line);

  while (std::getline(*file, line)) {
    std::istringstream iss(line);
    std::string date;
    float value;
    std::string tmp;

    // Try to read the date
    std::getline(iss, date, ' ');
    std::getline(iss, tmp, '|');
    std::getline(iss, tmp, ' ');

    // Try to read the value
    iss >> value;

    // Add the date and value to the list
    database.push_back(std::make_pair(date, value));
  }
  delete file;
  return database;
}

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

  // open file
  std::map<std::string, float> csv = create_database("data.csv");
  std::list<std::pair<std::string, float> > input = create_database_list(argv[1]);
  std::cout << csv << std::endl;
  std::cout << "perfect_input: " << input << std::endl;
  std::list<std::pair<std::string, float> > output;
  std::list<std::pair<std::string, float> >::iterator out_it = output.begin();

  for (std::list<std::pair<std::string, float> >::const_iterator it = input.begin(); it != input.end(); it++) {
    out_it = output.insert(out_it, *it);
    out_it->second = csv[it->first] * it->second;
    out_it++;
  }

  std::cout << "output: " << output << std::endl;
  // BitcoinExchange exchange;
  //
  // exchange.runExchange(file);
}
