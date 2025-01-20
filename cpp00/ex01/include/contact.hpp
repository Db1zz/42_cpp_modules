#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
public:
  // Contact constructor
  Contact(); // default class constructor
  Contact(const std::string& first_name,
          const std::string& last_name,
          const std::string& nickname,
          const std::string& phone_number,
          const std::string& darkest_secret);

  // Public functions
  const std::string& getFirstName() const;
  const std::string& getLastName() const;
  const std::string& getNickname() const;
  const std::string& getPhoneNumber() const;
  const std::string& getDarkestSecret() const;

  void setFirstName(const std::string& first_name);
  void setLastName(const std::string& last_name);
  void setNickname(const std::string& nickname);
  void setPhoneNumber(const std::string& phone_number);
  void setDarkestSecret(const std::string& darkest_secret);

 // Private member-variaBles
private:
  std::string first_name_;
  std::string last_name_;
  std::string nickname_;
  std::string phone_number_;
  std::string darkest_secret_;
};

#endif	// CONTACT_H