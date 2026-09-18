#include "Dog.hpp"
#include <iostream>

Dog::Dog()
 : Animal() , brain(new Brain())
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& other)
 : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *this->brain = *other.brain;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
    this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    return this->brain->getIdea(index);
}