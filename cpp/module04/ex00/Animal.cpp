#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
    *this = animal;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::Animal(std::string name) : type(name)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
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
    std::cout << "??? : im not animal!!!!!!!!!" << std::endl;
}
