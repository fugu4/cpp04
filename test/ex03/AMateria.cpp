#include "AMateria.hpp"

#include "ICharacter.hpp"

AMateria::AMateria(void) : type("")
{
}

AMateria::AMateria(std::string const& type) : type(type)
{
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
}

AMateria& AMateria::operator=(const AMateria& other)
{
	(void)other;
	return *this;
}

AMateria::~AMateria(void)
{
}

std::string const& AMateria::getType(void) const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
