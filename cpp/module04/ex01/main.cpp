#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Animal *meta[10];

	// for (size_t i = 0; i < 10; i++)
	// {
	// 	if (i % 2)
	// 	{
	// 		meta[i] = new Dog();
	// 	}
	// 	else
	// 	{
	// 		meta[i] = new Cat();
	// 	}
	// }
	// std::cout << std::endl;
	
	// for (size_t i = 0; i < 10; i++)
	// {
	// 	delete meta[i];
	// }
	// std::cout << std::endl;
	
	// std::string str;
	// Dog *d = new Dog();
	// Dog *d2 = new Dog();
	// std::cout << std::endl;
	// str = d->getBrain()->getIdea(0);
	// std::cout << "강아지의 첫번째 생각 : "<< str << std::endl;

	// d->getBrain()->setIdea("주인 나 배고프다...", 1);
	// str = d->getBrain()->getIdea(1);
	// std::cout << "강아지의 두번째 생각 : "<< str << std::endl;

	// *d2 = *d;
	// d2->getBrain()->setIdea("주인 나 산책 가고싶다....", 2);
	// str = d2->getBrain()->getIdea(2);
	// std::cout << "강아지의 세번째 생각 : "<< str << std::endl;

	// std::cout << std::endl;
	// delete d;
	// delete d2;

	Dog *d = new Dog();
	Dog *d2(d);
	Dog *d3;
	d3 = d;
	std::cout << std::endl;

	delete d;
	// delete d2;
	// delete d3;

	return 0;
}
