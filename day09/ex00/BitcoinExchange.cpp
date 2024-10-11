#include "BitcoinExchange.hpp"

std::ostream &operator<<(std::ostream &os, const std::map<std::string, float> &map) {
  for (std::map<std::string, float>::const_iterator it = map.begin(); it != map.end(); ++it) {
    os << "Key: " << it->first << ", Value: " << it->second << std::endl;
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::list<std::pair<std::string, float> > &lst) {
  for (std::list<std::pair<std::string, float> >::const_iterator it = lst.begin(); it != lst.end(); ++it) {
    os << "Key: " << it->first << ", Value: " << it->second << std::endl;
  }
  return os;
}
