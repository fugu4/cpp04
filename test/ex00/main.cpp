#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main(void)
{
	std::cout << "=== Animal polymorphism ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	delete cat;
	delete dog;
	delete meta;

	std::cout << std::endl << "=== WrongAnimal without virtual makeSound ===" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongMeta->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	delete wrongCat;
	delete wrongMeta;

	std::cout << std::endl << "=== Copy tests ===" << std::endl;
	Dog basicDog;
	Dog copiedDog(basicDog);
	Cat basicCat;
	Cat assignedCat;

	assignedCat = basicCat;
	copiedDog.makeSound();
	assignedCat.makeSound();

	return 0;
}
