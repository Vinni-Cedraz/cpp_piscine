#include "Contact.hpp"

class PhoneBook {
  private:
    Contact contacts[8];
    int idx;

  public:
    PhoneBook();

    void add_contact(
			std::string first_name,
			std::string last_name,
			std::string nickname,
			std::string phone_number,
            std::string darkest_secret
	);
	void add_CMD();
    void display_contacts();
};
