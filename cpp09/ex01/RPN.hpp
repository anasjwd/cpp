#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <exception>

class RPN {
	private:
		std::stack<int> numbers;
		std::string operators;
		RPN(void);

	public:
		RPN(std::string expression);
		~RPN(void);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		void parseExpression(const std::string& expression);
		int getResult(void) const;

		class InvalidElement : public std::exception {
			public:
				const char* what() const throw();
		};
		class IncompleteOperation	: public std::exception {
			public:
				const char* what() const throw();
		};
};
