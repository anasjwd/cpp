#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", 72, 45),
	target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm(other),
	target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
		const RobotomyRequestForm& other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	target = other.target;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (getIsSigned() == false)
		throw FormNotSigned();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::cout << "Drrrrrrrrr! Drrrrrrrrrr!" << std::endl;
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << target
			<< " has been robotomized successfully"
			<< std::endl;
	else
		std::cout << target << " robotomy has failed" << std::endl;
}
