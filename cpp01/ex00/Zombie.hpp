#pragma once
#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		Zombie(std::string name);
		void	announce(void);
	private:
		std::string	name;
};
