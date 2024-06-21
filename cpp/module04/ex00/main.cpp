#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// 다형성
// virtual 키워드를 사용하면, 해당 함수가 가상함수임을 명시한다.
// 가상함수는 상속받은 클래스에서 재정의할 수 있다.

// virtual table
// 가상함수를 사용하면, 가상함수 테이블(virtual table)이 생성
// 가상함수 테이블은 가상함수의 주소를 담고 있는 테이블
// 컴파일 단계에서 가상함수 테이블이 생성되며, 가상함수 테이블은 객체의 주소를 가지고 있다.
// 가상함수 테이블은 객체의 주소를 가지고 있으며, 객체의 주소를 통해 가상함수 테이블을 참조한다.

// 이번 과제에서는
// makeSound() 함수를 가상함수로 선언하고, 상속받은 클래스에서 재정의한다.
// makeSound() 함수는 각 동물의 울음소리를 출력한다.

// wrongAnimal 클래스는 가상함수를 사용하지 않아야함
// wrongAnimal 클래스의 makeSound() 함수는 가상함수가 아니므로, 상속받은 클래스에서 재정의할 수 없다.

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    // const WrongAnimal *meta2 = new WrongAnimal();
    // const WrongAnimal *i2 = new WrongCat();
    // meta2->makeSound();
    // i2->makeSound();
    // delete meta2;
    // delete i2;

    return 0;
}
