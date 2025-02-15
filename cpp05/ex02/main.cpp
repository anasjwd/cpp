#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat b("bob", 6);
	ShrubberyCreationForm s("home");
	RobotomyRequestForm r("space");
	PresidentialPardonForm p("vice president");

	std::cout << b << std::endl;
	std::cout << s << std::endl;
	std::cout << r << std::endl;
	std::cout << p << std::endl;
	std::cout << std::endl;
	b.signAForm(s);
	b.signAForm(r);
	b.signAForm(p);
	std::cout << std::endl;
	b.executeForm(s);
	std::cout << std::endl;
	b.executeForm(r);
	std::cout << std::endl;
	b.executeForm(p);
	return 0;
}
