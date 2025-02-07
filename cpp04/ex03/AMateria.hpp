#pragma once
#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string type;

	public:
		AMateria(void);
		AMateria(const std::string& type);
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria(void);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
