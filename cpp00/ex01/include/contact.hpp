#ifndef CONTACT_H
#define CONTACT_H

class Contact {
/*
  Public class functions/constructors and destructors
*/
public:
  // Class constructor/destructor
  Contact() = default;
  ~Contact();

  // Getters
  const char* getFirstName(void) const;
  const char* getLastName(void) const;
  const char* getNickname(void) const;
  const int* getPhoneNumber(void) const;
  const char* getDarkestSecret(void) const;

  // Setters
  void setFirstName(const char& first_name);
  void setLastName(const char& last_name);
  void setNickname(const char& nickname);
  void setPhoneNumber(int phone_number);
  void setDarkestSecret(const char& darkest_secret);

/*
  Private Functions
*/
private:
  void  freeAndSetString(char *dst, const char& src);

/*
  Private member-variaBles
*/
private:
  char *first_name_;
  char *last_name_;
  char *nickname_;
  int phone_number_;
  char *darkest_secret_;
};

#endif	// CONTACT_H