#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
  private:
    AMateria *slot[4];

  public:
    MateriaSource();
    MateriaSource(MateriaSource const &src);
    MateriaSource &operator=(const MateriaSource &src);
    ~MateriaSource();

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);
};
