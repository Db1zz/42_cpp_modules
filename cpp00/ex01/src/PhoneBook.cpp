#include "PhoneBook.hpp"
#include "Validator.hpp"
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>

#define FIELD_WIDTH 10

PhoneBook::PhoneBook()
  : max_contacts_(MAX_CONTACTS), contacts_added_(0), contacts_index_(0) {}

void PhoneBook::add(Contact& contact) {
  contacts_index_ = contacts_index_ % max_contacts_;
  contacts_[contacts_index_++] = contact;
  if (contacts_added_ < max_contacts_) {
    contacts_added_++;
  }
}

void PhoneBook::printTrunc(const std::string& str) const {
  if (str.size() < FIELD_WIDTH) {
      std::cout << std::right << std::setfill(' ')
                << std::setw(FIELD_WIDTH) << str;
  } else {
    std::cout << std::right << std::setfill(' ')
              << std::setw(FIELD_WIDTH)
              << str.substr(0, FIELD_WIDTH - 1) + ".";
  }
}

void PhoneBook::listContacts() const {
  std::cout << "     Index|" << " FirstName|" << "  LastName|" << "  NickName\n";
  for (int index = 0; index < contacts_added_; index++) {
    std::cout << std::setw(FIELD_WIDTH) << index << "|";
    printTrunc(contacts_[index].getFirstName());
    std::cout << "|";
    printTrunc(contacts_[index].getLastName());
    std::cout << "|";
    printTrunc(contacts_[index].getNickname());
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
