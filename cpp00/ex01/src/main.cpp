#include "PhoneBook.hpp"
#include "UI.hpp"
#include "Validator.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>

bool validate_phone_number(const std::string& phone_number) {
  PhoneNumberValidator validator;
  bool is_valid = validator.validate(phone_number);

  if (!is_valid)
    std::cout << "Error! Invalid phone number format! Try: +nnn n... or +nnnn...\n";
  return (is_valid);
}

void add_routine(PhoneBook& phone_book) {
  std::string first_name = UI::askStringInput("Contact first name: ");
  std::string last_name = UI::askStringInput("Contact last name: ");
  std::string nickname = UI::askStringInput("Contact nickname: ");
  std::string phone_number = UI::askStringInput("Contact phone number: ", validate_phone_number);
  std::string darkest_secret = UI::askStringInput("Contact darkest secret: ");
  if (UI::eof()) {
    std::cout << "CTRL + D DETECED: ADD command will be skipped\n";
    UI::clear_stream();
    return;
  }
  Contact new_contact(first_name, last_name, nickname, phone_number, darkest_secret);
  phone_book.add(new_contact);
}

void search_routine(const PhoneBook& phone_book) {
  if (phone_book.getContactsAmount() == 0) {
    std::cout << "There are no contacts in the phone book, so there's nothing to search for.\n";
    return;
  }
  phone_book.listContacts();
  while (true) {
    std::string user_input = UI::askStringInput("Choose contact by index: ");
    if (UI::eof()) {
      std::cout << "CTRL + D DETECED: Exiting search command\n";
      UI::clear_stream();
      break;
    }
    if (phone_book.displayContact(atoi(user_input.c_str()))) {
      break;
    }
  }
}

int main() {
  PhoneBook phone_book;
  while (true) {
    std::string user_input = UI::askStringInput("Enter one command from the list: [ADD, SEARCH, EXIT]: ");

    if (user_input == "ADD") {
      add_routine(phone_book);
    }
    else if (user_input == "SEARCH") {
      search_routine(phone_book);
    }
    else if (user_input == "EXIT" || UI::eof()) {
      break ;
    }
  }
  return 0;
}
