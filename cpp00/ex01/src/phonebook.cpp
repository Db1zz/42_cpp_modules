#include "PhoneBook.hpp"
#include "Validator.hpp"
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>

PhoneBook::PhoneBook()
  : max_contacts_(MAX_CONTACTS), contacts_added_(0), contacts_index_(0) {}

void PhoneBook::add(Contact& contact) {
  contacts_index_ = contacts_index_ % max_contacts_;
  contacts_[contacts_index_++] = contact;
  if (contacts_added_ < max_contacts_) {
    contacts_added_++;
  }
}

void PhoneBook::printTrunc(const std::string& str, int width) const {
  int str_len = static_cast<int>(str.length());
  int blank_len = width - str_len;

  blank_len = blank_len > 0 ? blank_len : 0;
  while (blank_len-- > 0) {
    std::cout << ' ';
  }
  if (str_len > width) {
    std::cout << str.substr(0, width - blank_len - 1) << '*';
  } else {
    std::cout << str;
  }
}

#define FIELD_WIDTH 10
void PhoneBook::listContacts() const {
  std::cout << "     Index|" << " FirstName|" << "  LastName|" << "  NickName\n";
  for (int index = 0; index < contacts_added_; index++) {
    std::cout << std::setw(10) << index << "|";
    printTrunc(contacts_[index].getFirstName(), FIELD_WIDTH);
    std::cout << "|";
    printTrunc(contacts_[index].getLastName(), FIELD_WIDTH);
    std::cout << "|";
    printTrunc(contacts_[index].getNickname(), FIELD_WIDTH);
    std::cout << std::endl;
  }
}

bool PhoneBook::displayContact(int contact_index) const {
  if (contact_index > contacts_added_ - 1) {
    std::cout << "Index is out of range. Valid index range is: 0 to " << contacts_added_ - 1 << std::endl;
    return false;
  }

  const Contact* contact = &contacts_[contact_index];
  std::cout << "Contact information: " << '\n';
  std::cout << "First Name: " << contact->getFirstName() << '\n';
  std::cout << "Last Name: " << contact->getLastName() << '\n';
  std::cout << "Nickname: " << contact->getNickname() << '\n';
  std::cout << "Phonenumber: " << contact->getPhoneNumber() << '\n';
  std::cout << "Darkest secret: " << contact->getDarkestSecret() << '\n';
  return true;
}

int PhoneBook::getContactsAmount() const {
  return contacts_added_;
}
