#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <exception>

class Intern {
	private:
		AForm* newShrubberyCreationForm(const std::string& target) const;
		AForm* newRobotomyRequestForm(const std::string& target) const;
		AForm* newPresidentialPardonForm(const std::string& target) const;

	public:
		class FormDoNotExist : public std::exception {
			public:
				const char* what() const throw();
		};
		Intern(void);
		~Intern(void);
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		AForm* makeForm(std::string name, std::string target) const;
};
