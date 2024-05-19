#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
  private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

  public:
    Contact();

    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getNickName() const;
    const std::string &getPhoneNumber() const;
    const std::string &getDarkestSecret() const;

    void setFirstName(std::string first_name);
    void setLastName(std::string last_name);
	void setNickName(std::string nickname);
	void setPhoneNumber(std::string phone_number);
	void setDarkestSecret(std::string darkest_secret);
};

#endif
