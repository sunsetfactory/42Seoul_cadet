#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
}

Dog::Dog(const Dog &dog)
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
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}
