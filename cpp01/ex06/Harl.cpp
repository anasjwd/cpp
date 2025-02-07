#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ debug ]: I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< "I really do!"
		<< std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ info ]: cannot believe adding extra bacon costs more mone"
		<< " You didn’t put enough bacon in my burger"
		<< "! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ warning ]: I think I deserve to have some extra bacon"
		<< " for free. "
		<< "’ve been coming for years whereas you started working here "
		<< "since last month."
		<< std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ error ]: This is unacceptable! I want to speak to the"
		<< " manager now."
		<< std::endl;
}

void	Harl::complain(std::string level)
{
	std::string logs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	idx = 0;

	while (idx < 4 && logs[idx] != level)
		idx++;
	switch (idx) {
		case 0:
			this->debug();
			this->info();
			this->warning();
			this->error();
			break;
		case 1:
			this->info();
			this->warning();
			this->error();
			break;
		case 2:
			this->warning();
			this->error();
			break;
		case 3:
			this->error();
			break;
		default:
			std::cout << "Invalid log level, please try again!" << std::endl;
			break;
	}
}
