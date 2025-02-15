#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 145, 137),
	target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
:	AForm(other),
	target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
		const ShrubberyCreationForm& other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	target = other.target;
	return *this;
}

void drawATree(std::ofstream& file)
{
	file << "         *         \n";
	file << "        * *        \n";
	file << "       *   *       \n";
	file << "      *     *      \n";
	file << "     *       *     \n";
	file << "    *         *    \n";
	file << "   *           *   \n";
	file << "  *             *  \n";
	file << " *               * \n";
	file << "*******************\n";
	file << "         |         \n";
	file << "         |         \n";
	file << "         |         \n";
	file << "         |         \n";
	file << "         |         \n";
	file << "         |         \n";
	file << "         |         \n";
	file << "iiiiiiiiiiiiiiiiiii\n";
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::ofstream file;
	std::string fileName = target + "_shrubbery";

	if (getIsSigned() == false)
		throw FormNotSigned();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	file.open(fileName.c_str());
	if (file.fail())
	{
		std::cout << "Failed: unable to open the file: " << fileName
			<< std::endl;
		return ;
	}
	drawATree(file);
}
