#pragma once
#include <vector>

class Span {
 private:
  unsigned int N;
  std::vector<int> numbers;

 public:
  Span(unsigned int N);
  Span();
  ~Span();
  Span(const Span &other);
  Span &operator=(const Span &other);
  void addNumber(int n);
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;
  void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};
