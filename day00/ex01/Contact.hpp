#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "Parser.hpp"

class Contact {
  private:
    user_input_t perfect_input;

  public:
    Contact();
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getNickName() const;
    const std::string &getPhoneNumber() const;
    const std::string &getDarkestSecret() const;
    const user_input_t getUserInput() const;

    void setUserInput(const user_input_t &perfect_input);
};

#endif
