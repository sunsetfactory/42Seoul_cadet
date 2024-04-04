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

void Animal::makeSound() const
{
    std::cout << "??? : ㅍ..피카?!!\n동물은 아무 말도 하지 않습니다. 이 메시지는 뭔가 잘못된 것입니다" << std::endl;
}
