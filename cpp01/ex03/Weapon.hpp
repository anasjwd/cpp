#pragma once
#include <string>

class Weapon {
	private:
		std::string	type;
		Weapon(void);

	public:
		~Weapon(void);
		Weapon(std::string _type);
		const std::string&	getType(void);
		void				setType(std::string type);
};
