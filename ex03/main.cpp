#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
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

    return 0;
}

// #include <iostream>

// int main()
// {
//     MateriaSource src;
//     src.learnMateria(new Ice());

//     Character original("original");
//     Character target("target");

//     AMateria* materia = src.createMateria("ice");
//     original.equip(materia);

//     Character copy(original);

//     original.unequip(0);
//     delete materia;

//     copy.use(0, target);

//     AMateria* unknown = src.createMateria("fire");

//     if (unknown == NULL)
//         std::cout << "fire materia was not found" << std::endl;
//     else
//         delete unknown;

//     return 0;
// }
