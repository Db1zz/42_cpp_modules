#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
public:
  Weapon();
  Weapon(std::string type);
  const std::string& getType() const;
  void setType(const std::string& type);

private:
  std::string _type;
};

#endif	// WEAPON_H
