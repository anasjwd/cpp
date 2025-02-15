#pragma once
#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
	private:
		std::string target;
		RobotomyRequestForm(void);
	
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		void execute(const Bureaucrat& executor) const;
};
