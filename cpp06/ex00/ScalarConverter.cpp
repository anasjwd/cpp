#include <iostream>
#include "ScalarConverter.hpp"
#include <cctype>
#include <sstream>

enum ScalarType {CHAR, INT, FLOAT, DOUBLE, UNDEFINED};

bool isChar(const std::string& scalar)
{
	if (scalar.length() != 3)
		return false;
	if (scalar.at(0) != '\'' || scalar.at(2) != '\'')
		return false;
	if (std::isprint(scalar.at(1)) == false)
		return false;
	return true;
}

bool isInt(const std::string& scalar)
{
	unsigned int length = scalar.length();
	unsigned int i = 0;
	std::istringstream ss(scalar);
	int holder;

	if (scalar.at(0) == '-' || scalar.at(0) == '+')
		i = 1;
	for (; i < length; i++)
	{
		if (std::isdigit(scalar.at(i)) == false)
			return false;
	}
	ss >> holder;
	return !ss.fail();
}

bool isFloat(const std::string& scalar)
{
	unsigned int length = scalar.length();
	unsigned int i = 0;
	int	numOfPoints = 0;
	int	numOfExpo = 0;
	std::istringstream ss(scalar);
	float holder;
	std::string validInput = ".eE+-";

	if (scalar.at(0) == '-' || scalar.at(0) == '+')
		i = 1;
	for (; i < length - 1; i++)
	{
		if (isdigit(scalar.at(i)) == false
				&& validInput.find(scalar.at(i)) == std::string::npos)
		{
			std::cout << "here" << std::endl;
			return false;
		}
		if (scalar.at(i) == '.' && numOfPoints++ > 1)
			return false;
		else if ((scalar.at(i) == 'e' || scalar.at(i) == 'E')
				&& (numOfExpo++ > 1 || numOfPoints == 0))
			return false;
		else if ((scalar.at(i) == '-' || scalar.at(i) == '+')
				&& (scalar.at(i - 1) != 'e' && scalar.at(i - 1) != 'E'))
	}
	if (scalar.at(i) != 'f' || numOfPoints != 1 || numOfExpo > 1)
	{
		std::cout << "here2" << std::endl;
		return false;
	}
	ss >> holder;
	std::cout << "here1" << std::endl;
	return !ss.fail();
}

bool isDouble(const std::string& scalar)
{
	unsigned int length = scalar.length();
	int numOfPoints = 0;

	for (unsigned int i = 0; i < length; i++)
	{
		if (isdigit(scalar.at(i)) == false && scalar.at(i) != '.')
			return false;
		if (scalar.at(i) == '.')
			numOfPoints++;
	}
	if (numOfPoints != 1)
		return false;
	return true;
}

ScalarType getScalarType(const std::string& scalar)
{
	bool (*checker[4])(const std::string& scalar) = {isChar, isInt, isFloat,
		isDouble};
	int i;

	for (i = 0; i < 4; i++)
	{
		if (checker[i](scalar) == true)
			break;
	}
	switch (i) {
		case CHAR:
			return CHAR;
		case INT:
			return INT;
		case FLOAT:
			return FLOAT;
		case DOUBLE:
			return DOUBLE;
	}
	return UNDEFINED;
}

/*void ScalarType::convertChar(const std::string& scalar)
{
}*/

void ScalarConverter::convert(const std::string& scalar)
{
	ScalarType type;
	/*void (*converter[4])(const std::string& scalar) = {&ScalarType::convertChar,
	 	&ScalarType::convertInt, &ScalarType::convertFloat,
	 	&ScalarType::convertDouble};*/

	if (scalar.empty() == true)
	{
		std::cout << "<error string empty>" << std::endl;
		return ;
	}
	type = getScalarType(scalar);
	if (type == UNDEFINED)
	{
		std::cout << "<error message here>" << std::endl;
		return ;
	}
	switch (type) {
		case CHAR:
			std::cout << "char\n";
			break;
		case INT:
			std::cout << "int\n";
			break;
		case FLOAT:
			std::cout << "float\n";
			break;
		case DOUBLE:
			std::cout << "double\n";
			break;
		default:
			std::cout << "uknown\n";
	}
	//converter[type](scalar);
}
