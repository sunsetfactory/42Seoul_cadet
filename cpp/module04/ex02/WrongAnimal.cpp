#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal)
{
    *this = WrongAnimal;
    std::cout << "두마리였나...?" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : type(name)
{
    std::cout << "저멀리 동물이 아닌 것이 보인다...!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "동물 분양 완료!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &WrongAnimal)
{
    this->type = WrongAnimal.getType();
    return *this;
}

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "저멀리 동물이 아닌 것이 보인다...!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "??? : ㅍ..피카?!!\n이상한 동물입니다. 이 메시지는 뭔가 잘못된 것입니다" << std::endl;
}
