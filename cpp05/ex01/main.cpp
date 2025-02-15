#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat b("bob", 150);
	Form f1("attestation1", 1, 1);
	Form f2("attestation2", 150, 1);

	std::cout << b << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	b.signForm(f1);
	b.signForm(f2);
	return 0;
}
