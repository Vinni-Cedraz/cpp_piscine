#include <algorithm>
#include <stdexcept>

#include "Span.hpp"

// Orthodox Cannonical Form:
Span::Span() : N() {}
Span::Span(unsigned int N) : N(N) {}
Span::Span(const Span &other) : N(other.N) { *this = other; }
Span &Span::operator=(const Span &other) {
  if (this == &other) return *this;
  N = other.N;
  numbers = other.numbers;
  return *this;
}
Span::~Span() {}

// Methods:
void Span::addNumber(int num) {
  if (numbers.size() >= N) {
    throw std::out_of_range("Span is full");
  }
  numbers.push_back(num);
}

unsigned int Span::longestSpan() const {
  const std::vector<int>::const_iterator begin = numbers.begin();
  const std::vector<int>::const_iterator end = numbers.end();
  if (numbers.size() < 2) {
    throw std::out_of_range("Span is too short");
  }
  return *std::max_element(begin, end) - *std::min_element(begin, end);
}

unsigned int Span::shortestSpan() const {
  if (numbers.size() < 2) {
    throw std::out_of_range("Span is too short");
  }
  std::vector<int> sorted = numbers;
  std::sort(sorted.begin(), sorted.end());
  unsigned int minSpan = sorted[1] - sorted[0];
  for (size_t i = 2; i < sorted.size(); i++) {
    unsigned int span = sorted[i] - sorted[i - 1];
    if (span < minSpan) minSpan = span;
  }
  return minSpan;
}

// operator overload
std::ostream &operator<<(std::ostream &out, const Span &rht) {
  const unsigned int size = rht.numbers.size();
  if (size > 0) {
    out << "Span[" << size << "]: ";
    for (size_t i = 0; i < size; i++) {
      out << rht.numbers[i];
      if (i < size - 1) out << ", ";
    }
  } else {
    out << "Span is empty";
  }
  return out;
}
