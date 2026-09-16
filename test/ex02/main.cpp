#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

static void testAnimalArray(void)
{
	const int count = 6;
	Animal* animals[count];

	for (int i = 0; i < count; ++i)
	{
		if (i < count / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < count; ++i)
		animals[i]->makeSound();
	for (int i = 0; i < count; ++i)
		delete animals[i];
}

static void testDeepCopy(void)
{
	Dog originalDog;
	originalDog.setIdea(0, "Chase the ball");
	Dog copiedDog(originalDog);
	copiedDog.setIdea(0, "Guard the house");

	std::cout << "original dog idea: " << originalDog.getIdea(0) << std::endl;
	std::cout << "copied dog idea: " << copiedDog.getIdea(0) << std::endl;

	Cat originalCat;
	Cat assignedCat;
	originalCat.setIdea(0, "Sleep on the keyboard");
	assignedCat = originalCat;
	assignedCat.setIdea(0, "Watch the window");

	std::cout << "original cat idea: " << originalCat.getIdea(0) << std::endl;
	std::cout << "assigned cat idea: " << assignedCat.getIdea(0) << std::endl;
}

int main(void)
{
	std::cout << "=== Abstract Animal through base pointers ===" << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	dog->makeSound();
	cat->makeSound();
	delete dog;
	delete cat;

	std::cout << std::endl << "=== Animal array ===" << std::endl;
	testAnimalArray();

	std::cout << std::endl << "=== Deep copy tests ===" << std::endl;
	testDeepCopy();

	return 0;
}
