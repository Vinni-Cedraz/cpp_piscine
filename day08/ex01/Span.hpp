#pragma once
#include <ostream>
#include <vector>

class Span {
 public:
  // methods:
  Span(unsigned int N);
  Span();
  ~Span();
  Span(const Span &other);
  Span &operator=(const Span &other);
  void addNumber(int n);
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;
  void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

  template <typename Iterator>
  void addRange(Iterator itBegin, Iterator itEnd) {
    while (itBegin != itEnd) {
      this->addNumber(*itBegin);
      itBegin++;
    }
  }

  // properties:
  unsigned int N;
  std::vector<int> numbers;
};

// operator overload <<
std::ostream &operator<<(std::ostream &lft, const Span &rht);
