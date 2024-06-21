#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>


// 전방선언이란? 전방선언은 컴파일러에게 이 변수는 나중에 정의될 것이라고
//*정의(definition)는 식별자(identifier)를 실제로 구현하거나 인스턴스화(메모리 할당) 한다. *
//*선언(declaration)은 식별자를 소개하고, 식별자가 나중에 정의될 것이라고 약속한다. *
class ICharacter;

class AMateria
{
  protected:
    std::string _type;

  public:
    AMateria();
    AMateria(AMateria const &src);
    AMateria &operator=(AMateria const &src);
    virtual ~AMateria();

    AMateria(std::string const &type);
    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif