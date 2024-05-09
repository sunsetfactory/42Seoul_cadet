#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "댕줍하다... 행복하다!" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal()
{
    *this = dog;
    std::cout << "댕댕줍하다... 행행복하다!!" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    this->type = dog.type;
    std::cout << "강쥐 묭실 다녀오는중... 똑같은 스타일 완성!" << std::endl;
    return *this;
    }

Dog::~Dog()
{
    std::cout << "강쥐 분양중..." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "왈 왈 !" << std::endl;
}
