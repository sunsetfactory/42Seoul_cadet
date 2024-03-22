#include "Dog.hpp"

int main() {
    Dog dog1("Fido", 3, "Golden Retriever");
    dog1.printInfo();
    dog1.makeSound();
    dog1.wagTail();
    return 0;
}
