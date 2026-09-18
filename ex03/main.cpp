#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();

    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    src->learnMateria(ice);
    src->learnMateria(cure);

    delete ice;
    delete cure;

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
//     IMateriaSource* ice_src = new MateriaSource();
//     IMateriaSource* cure_src = new MateriaSource();

//     AMateria* ice = new Ice();
//     AMateria* cure = new Cure();

//     for(int i = 0; i < 4; i++)
//         ice_src->learnMateria(ice);

//     ICharacter* me = new Character("me");
//     ICharacter* bob = new Character("bob");
//     AMateria* tmp;

//     for(int i = 0; i < 4; i++)
//     {
//         tmp = ice_src->createMateria("ice");
//         me->equip(tmp);
//         me->use(i, *bob);
//     }
//     std::cout << "------------" << std::endl;
//     me->unequip(2);
//     cure_src->learnMateria(cure);

//     tmp = cure_src->createMateria("cure");
//     me->equip(tmp);
//     for(int i = 0; i < 4; i++)
//     {
//         me->use(i, *bob);
//     }

//     delete bob;
//     delete me;
//     delete ice_src;
//     delete ice;
//     delete cure;
//     delete cure_src;

//     return 0;
// }
