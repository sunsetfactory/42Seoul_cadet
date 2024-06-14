#include "Floor.hpp"

Floor::Floor()
{
	for (int i = 0; i < 50; i++)
		_materia[i] = NULL;
}

Floor::~Floor()
{
	for (int i = 0; i < 50; i++)
	{
		if (_materia[i])
			delete _materia[i];
	}
}

void Floor::dropMateria(AMateria *m)
{
	if (_count >= 50)
	{
		if (_isFull == false)
			_isFull = true;
		_count = 0;
	}
	if (_isFull == false)
	{
		_materia[_count] = m;
		_count++;
	}
	else if (_isFull == true)
	{
		delete _materia[_count];
		_materia[_count] = m;
		_count++;
	}
}