#include "Character.hpp"

Character::Character()
	: name("")
{
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string const& name)
	: name(name)
{
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character& other)
	: name(other.name)
{
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	*this = other;
}

Character& Character::operator=(const Character& other)
{
	if(this != &other)
	{
		this->name = other.name;

		for(int i = 0; i < 4; i++)
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
			if(other.inventory[i] != NULL)
				this->inventory[i] = other.inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character
{
	for(int i = 0; i < 4; i++)
		delete this->inventory[i];
}


std::string const& Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	if(m == NULL)
		return;
	for(int i = 0; i < 4; i++)
	{
		if(this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if(idx < 0 || idx >= 4)
		return ;
	this->inventory[idx] == NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if(idx < 0 || idx >= 4)
		return;
	if(this->inventory[idx] == NULL)
		return;
	this->inventory[idx]->use(target);
}
