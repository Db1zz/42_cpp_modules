#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource()
  : _materias_learned(0)
{
  std::cout << "MateriaSource Constructor was called\n";
}

MateriaSource::MateriaSource(const MateriaSource& to_copy) {
  std::cout << "MateriaSource's Copy Constructor was called\n";
  copyMateriaList(to_copy);
}

MateriaSource::~MateriaSource() {
  std::cout << "MateriaSource Destructor was called\n";
  freeMateriaList();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& to_copy) {
  if (this == &to_copy) {
    return *this;
  }
  copyMateriaList(to_copy);
  return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
  if (materia == NULL) {
    return ;
  } else if (_materias_learned == LEARNED_MATERAIS_MAX) {
    return ;
  }
  _materias_list[_materias_learned] = materia;
  _materias_learned++;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
  for (int i = 0; i < _materias_learned; i++) {
    if (type == _materias_list[i]->getType()) {
      return _materias_list[i]->clone();
    }
  }
  return NULL;
}

void MateriaSource::freeMateriaList() {
  for (int i = 0; i < _materias_learned; i++) {
    free(_materias_list[i]);
  }
}

void MateriaSource::copyMateriaList(const MateriaSource& to_copy) {
  if (this == &to_copy) {
    return ;
  }
  for (int i = 0; i < LEARNED_MATERAIS_MAX; i++) {
    if (_materias_list[i]) {
      delete _materias_list[i];
    }
    _materias_list[i] = to_copy._materias_list[i]->clone();
  }
  _materias_learned = to_copy._materias_learned;
}
