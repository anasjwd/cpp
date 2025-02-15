#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const char* Form::GradeTooLowException::what() const throw()
{
	return "form's grade is too low";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "form's grade is too high";
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute):
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

Form::~Form(void)
{
}

Form::Form(const Form& other):
	name(other.name),
	isSigned(other.isSigned),
	gradeToSign(other.gradeToSign),
	gradeToExecute(other.gradeToExecute)
{
	if (gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
	if (this == &other)
		return *this;
	isSigned = other.isSigned;
	return *this;
}

const std::string& Form::getName(void) const
{
	return name;
}

const bool& Form::getIsSigned(void) const
{
	return isSigned;
}

const int& Form::getGradeToSign(void) const
{
	return gradeToSign;
}

const int& Form::getGradeToExecute(void) const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= gradeToSign)
		isSigned = true;
	else 
		throw GradeTooHighException();
}

std::ostream& operator<<(std::ostream& out, Form& f)
{
	out << f.getName() << ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute" << f.getGradeToExecute() << ", is ";
	if (f.getIsSigned() == true)
		out << "signed";
	else
		out << "not signed";
	return out;
}
