#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* storage[4];

	void initStorage(void);
	void clearStorage(void);
	void copyStorage(const MateriaSource& other);

public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	virtual ~MateriaSource(void);

	virtual void learnMateria(AMateria* materia);
	virtual AMateria* createMateria(std::string const& type);
};

#endif
