#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
public:
  // Constructor
  PhoneBook();

  // Public member functions
  void add(Contact& contact);
  void listContacts() const;
  bool displayContact(int contact_index) const;
  int getContactsAmount() const;

private:
  // Private functions
  void printTrunc(const std::string& str, int width) const;

  // Private member variables
  const int max_contacts_;
  int contacts_added_;
  int contacts_index_;
  Contact contacts_[MAX_CONTACTS];
};

#endif  // PHONEBOOK_H