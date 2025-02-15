#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Form's grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Form's grade is too high";
}

const char* AForm::FormNotSigned::what() const throw()
{
	return "Form is not signed";
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute):
	name(name),
	gradeToSign(gradeToSign),
	gradeToExecute(gradeToExecute)
{
	if (gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150)
		throw GradeTooLowException();
	isSigned = false;
}

AForm::~AForm(void)
{
}

AForm::AForm(const AForm& other):
	name(other.name),
	isSigned(other.isSigned),
	gradeToSign(other.gradeToSign),
	gradeToExecute(other.gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this == &other)
		return *this;
	isSigned = other.isSigned;
	return *this;
}

const std::string& AForm::getName(void) const
{
	return name;
}

const bool& AForm::getIsSigned(void) const
{
	return isSigned;
}

const int& AForm::getGradeToSign(void) const
{
	return gradeToSign;
}

const int& AForm::getGradeToExecute(void) const
{
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= gradeToSign)
		isSigned = true;
	else 
		throw GradeTooHighException();
}

std::ostream& operator<<(std::ostream& out, AForm& f)
{
	out << f.getName() << ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute " << f.getGradeToExecute() << ", is ";
	if (f.getIsSigned() == 1)
		out << "signed";
	else
		out << "not signed";
	return out;
}
