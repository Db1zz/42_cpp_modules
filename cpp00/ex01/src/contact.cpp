#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(
	const std::string &first_name,
	const std::string &last_name,
	const std::string &nickname,
	const std::string &phone_number,
	const std::string &darkest_secret)
	: first_name_(first_name),
	  last_name_(last_name),
	  nickname_(nickname),
	  phone_number_(phone_number),
	  darkest_secret_(darkest_secret) {}

const std::string& Contact::getFirstName() const {
  return first_name_;
}

const std::string& Contact::getLastName() const {
  return last_name_;
}

const std::string& Contact::getNickname() const {
  return nickname_;
}

const std::string& Contact::getPhoneNumber() const {
  return phone_number_;
}

const std::string& Contact::getDarkestSecret() const {
  return darkest_secret_;
}

void Contact::setFirstName(const std::string& first_name) {
  first_name_ = first_name;
}

void Contact::setLastName(const std::string& last_name) {
  last_name_ = last_name;
}

void Contact::setNickname(const std::string& nickname) {
  nickname_ = nickname;
}

void Contact::setPhoneNumber(const std::string& phone_number) {
  phone_number_ = phone_number;
}

void Contact::setDarkestSecret(const std::string& darkest_secret) {
  darkest_secret_ = darkest_secret;
}
