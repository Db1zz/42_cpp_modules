#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"

class PhoneBook {
/*
  Public class functions/constructors and destructors
*/
public:
  PhoneBook() = default;
  ~PhoneBook() = default;

  void  add();
  void  search();
  void  exit();

private:
  bool  askStringInput(const std::string& ask, std::string& result);

private:
  const int max_contact_index_;
  int current_contact_index;
  Contact contacts_[8];
};

#endif  // PHONEBOOK_H