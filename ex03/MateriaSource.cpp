#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
		this->templates[i] = NULL;
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if(this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->templates[i];
			this->templates[i] = NULL;
			if(other.templates[i] != NULL)
				this->templates[i] = other.templates[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->templates[i];
}


void MateriaSource::learnMateria(AMateria* m)
{
	if(m == NULL)
		return;
	for (int i = 0; i < 4; i++)
	{
		if(this->templates[i] == NULL)
		{
			this->templates[i] = m;
			return;
		}
	}

}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		 if (this->templates[i] != NULL && this->templates[i]->getType() == type)
            return this->templates[i]->clone();
	}
	return NULL;
}
