#include "contact.hpp"
#include <cstring>

Contact::~Contact() {
  delete[] first_name_;
  delete[] last_name_;
  delete[] nickname_;
  delete[] darkest_secret_;
}

const char* Contact::getFirstName(void) const {
  return first_name_ ? first_name_ : "";
}

const char* Contact::getLastName(void) const {
  return last_name_ ? last_name_ : "";
}

const char* Contact::getNickname(void) const {
  return nickname_ ? nickname_ : "";
}

const int* Contact::getPhoneNumber(void) const {
  return phone_number_ ? &phone_number_ : 0;
}

const char* Contact::getDarkestSecret(void) const {
  return darkest_secret_ ? darkest_secret_ : "";
}

void  Contact::freeAndSetString(char *dst, const char& src) {
  if (dst) {
    delete[] dst;
    dst = nullptr;
	}
  dst = new char[strlen(&src) + 1];
  strcpy(dst, &src);
}

void Contact::setFirstName(const char &first_name) {
  freeAndSetString(first_name_, first_name);
}

void Contact::setLastName(const char &last_name) {
  freeAndSetString(last_name_, last_name);
}

void Contact::setNickname(const char &nickname) {
  freeAndSetString(nickname_, nickname);
}

void Contact::setPhoneNumber(int phone_number) {
  phone_number_ = phone_number;
}

void Contact::setDarkestSecret(const char &darkest_secret) {
  freeAndSetString(darkest_secret_, darkest_secret);
}
