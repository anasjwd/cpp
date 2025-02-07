#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	harl.complain("INFO");
	harl.complain("ERROR");
	harl.complain("WARNING");
	harl.complain("DEBUG");
	harl.complain("ANAS");
	harl.complain("");
	return 0;
}
