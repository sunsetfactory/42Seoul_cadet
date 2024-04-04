#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
  private:
    std::string ideas[100];

  public:
    Brain();
    ~Brain();
    Brain(const Brain &brain);
    Brain &operator=(const Brain &brain);
    std::string getIdea(int index) const;
    void setIdea(std::string idea, int index);
};

#endif
