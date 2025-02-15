#pragma once
#include <string>
#include <exception>
#include <ostream>

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
		Form(void);
	
	public:
		Form(std::string name,
			int gradeToSign,
			int gradeToExecute);
		~Form(void);
		Form(const Form& other);
		Form& operator=(const Form& other);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		void beSigned(const Bureaucrat& b);
		const std::string& getName(void) const;
		const bool& getIsSigned(void) const;
		const int& getGradeToSign(void) const;
		const int& getGradeToExecute(void) const;
};

std::ostream& operator<<(std::ostream& out, Form& f);
