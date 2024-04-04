#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "저멀리 동물이 보인다...!" << std::endl;
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
    this->type = animal.getType();
    return *this;
}

std::string Animal::getType() const
{
    return this->type;
}
