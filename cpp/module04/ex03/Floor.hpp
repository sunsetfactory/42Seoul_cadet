#ifndef FLOOR_HPP
#define FLOOR_HPP

#include <iostream>
#include "AMateria.hpp"

class Floor
{
  private:
	AMateria	*_materia[50];
	bool 		_isFull;
	int 		_count;

	Floor &operator=(Floor const &src);
	Floor(Floor const &src);

  public:
	Floor();
	~Floor();

	void dropMateria(AMateria *m);
};

#endif