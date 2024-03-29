#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
}

Animal::Animal(const Animal &animal)
{
    *this = animal;
}

Animal::Animal(std::string name) : type(name)
{
}

Animal::~Animal()
{
}

Animal &Animal::operator=(const Animal &animal)
{
    if (this != &animal)
    {
        this->type = animal.type;
    }
    return *this;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}
