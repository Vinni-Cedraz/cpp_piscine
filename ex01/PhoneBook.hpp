#include "Contact.hpp"

typedef struct user_input_s {
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
} user_input_t;

class PhoneBook {
  private:
    Contact contacts[8];
    int idx;

  public:
    PhoneBook();

    void add_contact(user_input_t &user_input);
    void add_CMD();
    void display_contacts();
};
