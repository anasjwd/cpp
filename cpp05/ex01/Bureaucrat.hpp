#pragma once
#include <exception>
#include <string>
#include <ostream>

class Form;

class Bureaucrat {
	private:
		const std::string name;
		int grade;
		Bureaucrat(void);
	
	public:
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		const std::string& getName(void) const;
		int getGrade(void) const;
		void increment(void);
		void decrement(void);
		void signForm(Form& f) const;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& b);
