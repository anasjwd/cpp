#include "Intern.hpp"

const char* Intern::FormDoNotExist::what() const throw()
{
	return "form doesn't exist";
}

Intern::Intern(void)
{
}

Intern::~Intern(void)
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

AForm* Intern::newShrubberyCreationForm(const std::string& target) const
{
	return ( new ShrubberyCreationForm(target) );
}

AForm* Intern::newRobotomyRequestForm(const std::string& target) const
{
	return ( new RobotomyRequestForm(target) );
}

AForm* Intern::newPresidentialPardonForm(const std::string& target) const
{
	return ( new PresidentialPardonForm(target) );
}

AForm* Intern::makeForm(std::string name, std::string target) const
{
	std::string forms[3] = {"shrubbery creation", "robotomy request",
		"presidential pardon"};
	AForm* (Intern::*creators[3])(const std::string&) const =
	{&Intern::newShrubberyCreationForm, &Intern::newRobotomyRequestForm,
		&Intern::newPresidentialPardonForm};
	
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == name)
			return (this->*creators[i])(target);
	}
	throw FormDoNotExist();
}
