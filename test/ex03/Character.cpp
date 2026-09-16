#include "Character.hpp"

#include "AMateria.hpp"

Character::Character(void) : name(""), floor(0)
{
	this->initInventory();
}

Character::Character(const std::string& name) : name(name), floor(0)
{
	this->initInventory();
}

Character::Character(const Character& other) : name(other.name), floor(0)
{
	this->initInventory();
	this->copyInventory(other);
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->clearInventory();
		this->clearFloor();
		this->name = other.name;
		this->copyInventory(other);
	}
	return *this;
}

Character::~Character(void)
{
	this->clearInventory();
	this->clearFloor();
}

void Character::initInventory(void)
{
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = 0;
}

void Character::clearInventory(void)
{
	for (int i = 0; i < 4; ++i)
	{
		delete this->inventory[i];
		this->inventory[i] = 0;
	}
}

void Character::clearFloor(void)
{
	DroppedMateria* current = this->floor;

	while (current != 0)
	{
		DroppedMateria* next = current->next;
		delete current->materia;
		delete current;
		current = next;
	}
	this->floor = 0;
}

void Character::copyInventory(const Character& other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory[i] != 0)
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = 0;
	}
}

void Character::dropMateria(AMateria* materia)
{
	if (materia == 0)
		return;

	DroppedMateria* node = new DroppedMateria;
	node->materia = materia;
	node->next = this->floor;
	this->floor = node;
}

std::string const& Character::getName(void) const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	if (m == 0)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (this->inventory[i] == m)
			return;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (this->inventory[i] == 0)
		{
			this->inventory[i] = m;
			return;
		}
	}
	this->dropMateria(m);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || this->inventory[idx] == 0)
		return;
	this->dropMateria(this->inventory[idx]);
	this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || this->inventory[idx] == 0)
		return;
	this->inventory[idx]->use(target);
}
