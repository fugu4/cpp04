#include "Cat.hpp"
#include <iostream>

Cat::Cat()
  : Animal(), brain(new Brain())
{
  std::cout << "Cat default constructor called" << std::endl;
  this->type = "Cat";
}

Cat::Cat(const Cat& other)
  : Animal(other), brain(new Brain(*other.brain))
{
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
  std::cout << "Cat copt assignment operator called" << std::endl;
  if(this != &other)
  {
    Animal::operator=(other);
    *this->brain = *other.brain;
  }
  return *this;
}

Cat::~Cat()
{
  std::cout << "Cat destructed" << std::endl;
  delete this->brain;
}

void Cat::makeSound() const
{
  std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
    this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
    return this->brain->getIdea(index);
}