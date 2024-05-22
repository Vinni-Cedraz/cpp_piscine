#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
  private:
    Contact contacts[8];
    int idx;

  public:
    PhoneBook();

    void add_contact(const user_input_t &user_input);
    void add_CMD();
    void display_contacts();
};

#endif
