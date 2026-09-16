#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

static void runAdditionalTests(void)
{
	MateriaSource source;
	Character alice("alice");
	Character copy("copy");

	source.learnMateria(new Ice());
	source.learnMateria(new Cure());
	source.learnMateria(new Ice());
	source.learnMateria(new Cure());
	source.learnMateria(new Ice());

	alice.equip(source.createMateria("ice"));
	alice.equip(source.createMateria("cure"));
	alice.equip(source.createMateria("unknown"));
	alice.unequip(0);
	alice.unequip(42);
	copy = alice;
}

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	runAdditionalTests();

	return 0;
}
