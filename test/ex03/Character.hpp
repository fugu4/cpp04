#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	struct DroppedMateria
	{
		AMateria* materia;
		DroppedMateria* next;
	};

	std::string name;
	AMateria* inventory[4];
	DroppedMateria* floor;

	void initInventory(void);
	void clearInventory(void);
	void clearFloor(void);
	void copyInventory(const Character& other);
	void dropMateria(AMateria* materia);

public:
	Character(void);
	Character(const std::string& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	virtual ~Character(void);

	virtual std::string const& getName(void) const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif
