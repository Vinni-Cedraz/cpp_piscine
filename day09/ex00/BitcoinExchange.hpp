#pragma once

#include <unistd.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <ostream>
#include <sstream>

class BitcoinExchange {};

std::ostream &operator<<(std::ostream &os, const std::map<std::string, float> &map);
std::ostream &operator<<(std::ostream &os, const std::list<std::pair<std::string, float> > &lst);
