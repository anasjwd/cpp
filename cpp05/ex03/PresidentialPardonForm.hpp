#pragma once
#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
	private:
		std::string target;
		PresidentialPardonForm(void);
	
	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		void execute(const Bureaucrat& executor) const;
};
