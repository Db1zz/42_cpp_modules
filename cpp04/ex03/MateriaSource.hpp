#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "AMateria.hpp"

#define LEARNED_MATERAIS_MAX 4

class IMateriaSource {
public:
  virtual ~IMateriaSource() {};
  virtual void learnMateria(AMateria*) = 0;
  virtual AMateria* createMateria(const std::string& type) = 0;
};

class MateriaSource : public IMateriaSource {
public:
  MateriaSource();
  MateriaSource(const MateriaSource& to_copy);
  virtual ~MateriaSource();
  MateriaSource& operator=(const MateriaSource& to_copy);

  void learnMateria(AMateria* materia);
  AMateria* createMateria(const std::string& type);

private:
  void freeMateriaList();
  void copyMateriaList(const MateriaSource& to_copy);

  int _materias_learned;
  AMateria* _materias_list[LEARNED_MATERAIS_MAX];
};

#endif  // MATERIA_SOURCE_HPP