#pragma once
#include <string>
#include <exception>
#include <ostream>

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
		AForm(void);
	
	public:
		AForm(std::string name,
			int gradeToSign,
			int gradeToExecute);
		virtual ~AForm(void);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class FormNotSigned : public std::exception {
			public:
				const char* what() const throw();
		};

		const std::string& getName(void) const;
		const bool& getIsSigned(void) const;
		const int& getGradeToSign(void) const;
		const int& getGradeToExecute(void) const;

		void beSigned(const Bureaucrat& b);
		virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, AForm& f);
