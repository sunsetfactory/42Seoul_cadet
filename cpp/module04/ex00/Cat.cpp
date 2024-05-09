#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "냥줍하다... 사랑하다!" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal("Cat")
{
    *this = cat;
    std::cout << "냥냥줍하다... 사랑사랑하다!!" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    this->type = cat.type;
    std::cout << "냥이 묭실 다녀오는중... 미용사 블러딩중..." << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "냥이 분양중..." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "냐옹 냐옹 냐옹 냐옹 냐옹" << std::endl;
}
