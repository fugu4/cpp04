#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main()
{
    const int size = 10;
    Animal* animals[size];

    for (int i = 0; i < size; i++)
    {
        if(i < size / 2)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }
    std::cout << "--------------------" << std::endl;

    for (int i = 0; i < size; i++)
        animals[i]->makeSound();
    std::cout << "--------------------" << std::endl;

    for(int i = 0; i < size; i++)
        delete animals[i];

    std::cout << "-- deep copy test --" << std::endl;

Dog original;
original.setIdea(0, "I want a bone");

Dog copy(original);

std::cout << "original: " << original.getIdea(0) << std::endl;
std::cout << "copy: " << copy.getIdea(0) << std::endl;

original.setIdea(0, "I want to sleep");

std::cout << "original after change: " << original.getIdea(0) << std::endl;
std::cout << "copy after original changed: " << copy.getIdea(0) << std::endl;

    return 0;

}
