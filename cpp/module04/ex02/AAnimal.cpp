#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal")
{
    std::cout << "저멀리 동물이 보인다...!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &Animal)
{
    std::cout << "두마리였나...?" << std::endl;
    this->type = Animal.getType();
}

AAnimal::AAnimal(std::string name) : type(name)
{
    std::cout << "저멀리 동물이 보인다...!" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "동물 분양 완료!" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &Animal)
{
    this->type = Animal.getType();
    return *this;
}

std::string AAnimal::getType() const
{
    return this->type;
}
