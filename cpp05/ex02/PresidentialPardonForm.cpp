#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", 25, 5),
	target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm::PresidentialPardonForm(
		const PresidentialPardonForm& other):
	AForm(other),
	target(other.target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
		const PresidentialPardonForm& other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	target = other.target;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (getIsSigned() == false)
		throw FormNotSigned();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::cout << target << " had been pardoned by Zaphod Beeblebrox"
		<< std::endl;
}
