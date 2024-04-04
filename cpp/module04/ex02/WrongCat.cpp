#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "냥줍하다... 사랑하다!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &WrongCat) : WrongAnimal("WrongCat")
{
    *this = WrongCat;
    std::cout << "냥냥줍하다... 사랑사랑하다!!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &WrongCat)
{
    this->type = WrongCat.type;
    std::cout << "냥이 묭실 다녀오는중... 미용사 블러딩중..." << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "냥이 분양중..." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "냐옹 냐옹 냐옹 냐옹 냐옹" << std::endl;
}
