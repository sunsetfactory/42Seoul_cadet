#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "냥줍하다... 고양이 맞아..?" << std::endl;
}

WrongCat::WrongCat(const WrongCat &WrongCat) : WrongAnimal("WrongCat")
{
    *this = WrongCat;
    std::cout << "냥냥줍하다... 고고양이 맞아?" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &WrongCat)
{
    this->type = WrongCat.type;
    std::cout << "냥이 묭실 다녀오는중... 미용사의 표정이 이상하다..." << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "냥이라 생각되는 무언가 분양중..." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "먀몽 먀몽 먀몽 먀몽 먀몽" << std::endl;
}
