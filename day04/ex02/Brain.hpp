#pragma once

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

#include <string>

class Brain {
  public:
    Brain();
    Brain(const Brain &obj);
    ~Brain();
    Brain &operator=(const Brain &cpy);
    std::string getIdea(size_t index) const;
    void setIdea(size_t index, std::string idea);

  private:
    std::string _ideas[100];
};
