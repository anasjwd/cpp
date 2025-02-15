#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;
		ShrubberyCreationForm(void);

	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		void execute(const Bureaucrat& executor) const;
};
