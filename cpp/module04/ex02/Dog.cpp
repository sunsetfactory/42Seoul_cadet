#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
    this->brain = new Brain();
    std::cout << "댕줍하다... 행복하다!" << std::endl;
}

Dog::Dog(const Dog &dog) : AAnimal()
{
    this->brain = new Brain(*dog.brain);
    this->type = dog.type;
    std::cout << "댕댕줍하다... 행행복하다!!" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    // delete this->brain;
    // this->brain = new Brain(*dog.brain);

    *this->brain = *dog.brain;
    this->type = dog.type;
    std::cout << "강쥐 묭실 다녀오는중... 똑같은 스타일 완성!" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "강쥐 분양중..." << std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "왈 왈 !" << std::endl;
}

Brain *Dog::getBrain() const
{
    return this->brain;
}
