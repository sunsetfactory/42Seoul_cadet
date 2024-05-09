#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(AMateria const &src)
{
    _type = src._type;
}

AMateria &AMateria::operator=(AMateria const &src)
{
    _type = src._type;
    return *this;
}

AMateria::~AMateria()
{
}

AMateria::AMateria(std::string const &type) : _type(type)
{
}

std::string const &AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter &target)
{
    (void)target;
    return;
}
