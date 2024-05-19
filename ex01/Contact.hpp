#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
  private:
    std::string name;
    std::string number;

  public:
    // constructors-destructor:
    Contact();
    Contact(const std::string &name, const std::string &number);

    // setters-getters:
    void setNameNumber(const std::string &name, const std::string &number);
    const std::string &getName() const;
    const std::string &getNumber() const;
};

#endif
