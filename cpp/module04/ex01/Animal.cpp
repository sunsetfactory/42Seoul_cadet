#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
    *this = animal;
    std::cout << "두마리였나...?" << std::endl;
}

Animal::Animal(std::string name) : type(name)
{
    std::cout << "저멀리 동물이 보인다...!" << std::endl;
}

Animal::~Animal()
{
    std::cout << "동물 분양 완료!" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
    this->type = animal.type;
    return *this;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "??? : Pi.. pika? Pikaaaaaaaaachuuuuuuuuuuuu!!" << std::endl;
}

Brain *Animal::getBrain() const
{
    return this->brain;
}
