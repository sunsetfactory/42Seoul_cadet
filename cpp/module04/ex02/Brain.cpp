#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "동물과 인사중 ..." << std::endl;
}

Brain::~Brain()
{
    std::cout << "추억을 묻어 두는 중..." << std::endl;
}

Brain::Brain(const Brain &brain)
{
    std::cout << "추억을 복사 중..." << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = brain.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &brain)
{
    std::cout << "기억을 공유 중..." << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = brain.ideas[i];
    }
    return *this;
}

std::string Brain::getIdea(int index) const
{
    return this->ideas[index];
}

void Brain::setIdea(std::string idea, int index)
{
    this->ideas[index] = idea;
}
