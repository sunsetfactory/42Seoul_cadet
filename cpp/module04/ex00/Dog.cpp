#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
}

Dog::Dog(const Dog &dog) : Animal("Dog")
{
    *this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
    if (this != &dog)
    {
        this->type = dog.type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}
