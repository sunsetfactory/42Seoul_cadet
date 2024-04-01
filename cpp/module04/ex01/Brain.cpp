#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "동물과 인사중 ..." << std::endl;
}

Brain::~Brain()
{
    std::cout << "이별을 기약중 ... 안녕 잘가!" << std::endl;
}

Brain::Brain(const Brain &brain)
{
    *this = brain;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = brain.getIdea(i);
    }
    return *this;
    std::cout << "Brain assignation operator called" << std::endl;
}

std::string Brain::getIdea(int index) const
{
    return this->ideas[index];
}

void Brain::setIdea(std::string idea, int index)
{
    this->ideas[index] = idea;
}
