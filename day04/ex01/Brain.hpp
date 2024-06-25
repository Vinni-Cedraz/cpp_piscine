#pragma once

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
    std::string ideas[100];
};
