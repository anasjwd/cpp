#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat b("bob", 1);
	Intern mossab;

	AForm* s = mossab.makeForm("shrubbery creation", "home");
	AForm* r = mossab.makeForm("robotomy request", "space");
	AForm* p = mossab.makeForm("presidential pardon", "vice president");

	std::cout << b << std::endl;
	std::cout << *s << std::endl;
	std::cout << *r << std::endl;
	std::cout << *p << std::endl;
	std::cout << std::endl;
	b.signAForm(*s);
	b.signAForm(*r);
	b.signAForm(*p);
	std::cout << std::endl;
	b.executeForm(*s);
	std::cout << std::endl;
	b.executeForm(*r);
	std::cout << std::endl;
	b.executeForm(*p);
	std::cout << std::endl;
	
	delete s;
	delete r;
	delete p;

	std::string name = "DoNotExist";
	try {
		AForm* f = mossab.makeForm(name, "target");
		b.signAForm(*f);
	}
	catch (std::exception& e)
	{
		std::cout << "Failed to create " << name << " because ";
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
