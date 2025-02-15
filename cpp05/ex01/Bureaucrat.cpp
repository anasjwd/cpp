#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade):
	name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):
	name(other.name)
{
	grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return *this;
	grade = other.grade;
	return *this;
}

const std::string& Bureaucrat::getName(void) const
{
	return name;
}

int Bureaucrat::getGrade(void) const
{
	return grade;
}

void Bureaucrat::increment(void)
{
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	--grade;
}

void Bureaucrat::decrement(void)
{
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	++grade;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade "
		<< b.getGrade();
	return out;
}

void Bureaucrat::signForm(Form& f) const
{
	try {
		f.beSigned(*this);
	}
	catch (std::exception& e) {
		std::cout << name << " couldn't sign " << f.getName() << " because "
			<< e.what() << std::endl;
		return ;
	}
	std::cout << name << " signed " << f.getName() << std::endl;;
}
