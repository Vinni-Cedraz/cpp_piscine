#include "Contact.hpp"

class PhoneBook {
  private:
    Contact contacts[8];
    int idx;

  public:
    PhoneBook();

    void add_contact(std::string name, std::string number);
    void display_contacts();
};
