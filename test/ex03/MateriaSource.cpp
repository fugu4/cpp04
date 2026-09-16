#include "MateriaSource.hpp"

#include "AMateria.hpp"

MateriaSource::MateriaSource(void)
{
	this->initStorage();
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	this->initStorage();
	this->copyStorage(other);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		this->clearStorage();
		this->copyStorage(other);
	}
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	this->clearStorage();
}

void MateriaSource::initStorage(void)
{
	for (int i = 0; i < 4; ++i)
		this->storage[i] = 0;
}

void MateriaSource::clearStorage(void)
{
	for (int i = 0; i < 4; ++i)
	{
		delete this->storage[i];
		this->storage[i] = 0;
	}
}

void MateriaSource::copyStorage(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.storage[i] != 0)
			this->storage[i] = other.storage[i]->clone();
		else
			this->storage[i] = 0;
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (materia == 0)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (this->storage[i] == 0)
		{
			this->storage[i] = materia->clone();
			delete materia;
			return;
		}
	}
	delete materia;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->storage[i] != 0 && this->storage[i]->getType() == type)
			return this->storage[i]->clone();
	}
	return 0;
}
