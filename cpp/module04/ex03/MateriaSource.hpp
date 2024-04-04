#ifndef MATERIALSOURCE_HPP
#define MATERIALSOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  private:
    AMateria *_source[4];

  public:
    MateriaSource();
    MateriaSource(MateriaSource const &src);
    ~MateriaSource();
    MateriaSource &operator=(MateriaSource const &rhs);

    void learnMateria(AMateria *m);
    AMateria *createMateria(std::string const &type);
};

#endif
