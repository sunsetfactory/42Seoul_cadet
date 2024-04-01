#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    this->brain = new Brain();
    std::cout << "냥줍하다... 사랑하다!" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal("Cat")
{
    this->brain = new Brain(*cat.brain);
    *this = cat;
    std::cout << "냥냥줍하다... 사랑사랑하다!!" << std::endl;
}

// Cat &Cat::operator=(const Cat &cat)
// {
//     this->brain = cat.brain;
//     this->type = cat.type;
//     return *this;
// }

Cat &Cat::operator=(const Cat &cat)
{
    Brain *tmp = cat.getBrain();
    Brain *tmp2 = this->getBrain();
    *tmp2 = *tmp;
    this->type = cat.type;

    // delete this->brain;
    // this->brain = new Brain(*cat.brain);
    // this->type = cat.type;
    std::cout << "냥이 묭실 다녀오는중... 미용사 블러딩중..." << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "냥이 분양중..." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "냐옹 냐옹 냐옹 냐옹 냐옹" << std::endl;
}

Brain *Cat::getBrain() const
{
    return this->brain;
}
