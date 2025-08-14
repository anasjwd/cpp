#include "RPN.hpp"

enum Type {
	INVALID,
	NUMBER,
	OPERATOR
};

RPN::RPN(const std::string expression) {
	parseExpression(expression);
}

RPN::~RPN(void) {}

RPN::RPN(const RPN& other) {
	numbers = other.numbers;
}

RPN& RPN::operator=(const RPN& other) {
	if (this == &other)
		return ( *this );
	numbers = other.numbers;
	return ( *this );
}

static int toInt(std::string& str)
{
	std::stringstream ss(str);
	int num;
	ss >> num;
	if (ss.fail() || !ss.eof())
		return ( -1 );
	return ( num );
}

static Type identifyElm(std::string& elm)
{
	if (elm.size() != 1)
		return ( INVALID );
	std::string ops("+-*/");
	if (ops.find(elm) != std::string::npos)
		return ( OPERATOR );
	else if (elm[0] >= '0' && elm[0] <= '9')
		return ( NUMBER );
	return ( INVALID );
}

static int operation(int& first, int& second, std::string& op) {
	if (op == "*")
		return ( first * second );
	else if (op == "+")
		return ( first + second );
	else if (op == "-")
		return ( first - second );
	else if (op == "/")
		return ( first / second );
	return ( 0 );
}

void RPN::parseExpression(const std::string& expression) {
	std::stringstream ss(expression);
	std::string frag;
	Type type;
	int num;
	int first;
	int second;
	while (getline(ss, frag, ' '))
	{
		type = identifyElm(frag);
		if (type == INVALID) {
			throw InvalidElement();
		} else if (type == NUMBER) {
			num = toInt(frag);
			if (num == -1) {
				throw InvalidElement();
			}
			numbers.push(num);
		} else if (type == OPERATOR) {
			if (numbers.size() < 2) {
				throw InvalidElement();
			}
			second = numbers.top();
			numbers.pop();
			first = numbers.top();
			numbers.pop();
			numbers.push(operation(first, second, frag));
		}
	}
}

int RPN::getResult(void) const {
	if (numbers.size() != 1) throw IncompleteOperation();
	return ( numbers.top() );
}

const char* RPN::InvalidElement::what() const throw() {
	return ( "Error: Invalid Element" );
}

const char* RPN::IncompleteOperation::what() const throw() {
	return ( "Error: Incomplete operation" );
}
