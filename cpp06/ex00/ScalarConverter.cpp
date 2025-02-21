#include <iostream>
#include "ScalarConverter.hpp"
#include <cctype>
#include <sstream>
#include <iomanip>
#include <limits>

char ScalarConverter::charScalar = 0;
int ScalarConverter::intScalar = 0;
float ScalarConverter::floatScalar = 0;
double ScalarConverter::doubleScalar = 0;

bool ScalarConverter::isChar(const std::string& scalar)
{
	if (scalar.length() != 3)
		return false;
	if (scalar.at(0) != '\'' || scalar.at(2) != '\'')
		return false;
	if (std::isprint(scalar.at(1)) == false)
		return false;
	return true;
}

bool ScalarConverter::isInt(const std::string& scalar)
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

bool ScalarConverter::isFloat(const std::string& scalar)
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
			return false;
		if (scalar.at(i) == '.' && numOfPoints++ > 0)
			return false;
		else if ((scalar.at(i) == 'e' || scalar.at(i) == 'E')
				&& (numOfExpo++ > 0 || numOfPoints == 0))
			return false;
		else if ((scalar.at(i) == '-' || scalar.at(i) == '+')
				&& (scalar.at(i - 1) != 'e' && scalar.at(i - 1) != 'E'))
			return false;
	}
	if (scalar.at(i) != 'f')
		return false;
	ss >> holder;
	return !ss.fail();
}

bool ScalarConverter::isDouble(const std::string& scalar)
{
	unsigned int length = scalar.length();
	unsigned int i = 0;
	int	numOfPoints = 0;
	int	numOfExpo = 0;
	std::istringstream ss(scalar);
	double holder;
	std::string validInput = ".eE+-";

	if (scalar.at(0) == '-' || scalar.at(0) == '+')
		i = 1;
	for (; i < length; i++)
	{
		if (isdigit(scalar.at(i)) == false
				&& validInput.find(scalar.at(i)) == std::string::npos)
			return false;
		if (scalar.at(i) == '.' && numOfPoints++ > 0)
			return false;
		else if ((scalar.at(i) == 'e' || scalar.at(i) == 'E')
				&& (numOfExpo++ > 0 || numOfPoints == 0))
			return false;
		else if ((scalar.at(i) == '-' || scalar.at(i) == '+')
				&& (scalar.at(i - 1) != 'e' && scalar.at(i - 1) != 'E'))
			return false;
	}
	ss >> holder;
	return !ss.fail();
}

ScalarType ScalarConverter::getScalarType(const std::string& scalar)
{
	bool (*checker[])(const std::string& scalar) = {isChar, isInt, isFloat,
		isDouble, isPseudo};
	int i;

	for (i = 0; i < 5; i++)
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
		case PSEUDO:
			return PSEUDO;
	}
	return UNDEFINED;
}

void ScalarConverter::convertFromChar(const std::string& scalar)
{
	charScalar = scalar[1];
	intScalar = static_cast<int>(charScalar);
	floatScalar = static_cast<float>(charScalar);
	doubleScalar = static_cast<double>(charScalar);
	printConversions(charScalar);
}

void ScalarConverter::convertFromInt(const std::string& scalar)
{
	std::istringstream ss(scalar);

	ss >> intScalar;
	charScalar = static_cast<char>(intScalar);
	floatScalar = static_cast<float>(intScalar);
	doubleScalar = static_cast<double>(intScalar);
	printConversions(intScalar);
}

void ScalarConverter::convertFromFloat(const std::string& scalar)
{
	std::istringstream ss(scalar);

	ss >> floatScalar;
	charScalar = static_cast<char>(floatScalar);
	intScalar = static_cast<int>(floatScalar);
	doubleScalar = static_cast<double>(floatScalar);
	printConversions(floatScalar);
}

void ScalarConverter::convertFromDouble(const std::string& scalar)
{
	std::istringstream ss(scalar);

	ss >> doubleScalar;
	charScalar = static_cast<char>(doubleScalar);
	intScalar = static_cast<int>(doubleScalar);
	floatScalar = static_cast<double>(doubleScalar);
	printConversions(doubleScalar);
}

void ScalarConverter::printConversions(double givenValue)
{
	std::cout << "char: ";
	if (std::numeric_limits<char>::min() > givenValue
			|| std::numeric_limits<char>::max() < givenValue)
		std::cout << "impossible" << std::endl;
	else if (isprint(charScalar))
		std::cout << "\'" << charScalar << '\'' << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (std::numeric_limits<int>::min() > givenValue
			|| std::numeric_limits<int>::max() < givenValue)
		std::cout << "impossible" << std::endl;
	else
		std::cout  << intScalar << std::endl;

	std::cout << "float: ";
	if (floatScalar == std::numeric_limits<float>::infinity())
		std::cout << "inff" << std::endl;
	else if (floatScalar == (-std::numeric_limits<float>::infinity()))
		std::cout << "-inff" << std::endl;
	else if ((-std::numeric_limits<float>::max()) > givenValue
			|| std::numeric_limits<float>::max() < givenValue)
		std::cout << "impossible" << std::endl;
	else
	{
		std::cout << floatScalar;
		if (floatScalar == intScalar)
			std::cout << ".0";
		std::cout << 'f' << std::endl;
	}

	std::cout << "double: " << doubleScalar;
	if (doubleScalar == intScalar)	
		std::cout << ".0";
	std::cout << std::endl;
}

bool ScalarConverter::isPseudo(const std::string& scalar)
{
	std::string pseudo[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++)
	{
		if (scalar == pseudo[i])
			return true;
	}
	return false;
}

void ScalarConverter::convertFromPseudo(const std::string& scalar)
{
	if (scalar == "-inff" || scalar == "+inff" || scalar == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << scalar << std::endl;
		std::cout << "double: " << scalar.substr(0, scalar.length() - 1) << std::endl;
	}
	else if (scalar == "-inf" || scalar == "+inf" || scalar == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << scalar << 'f' << std::endl;
		std::cout << "double: " << scalar << std::endl;
	}	
}

void ScalarConverter::convert(const std::string& scalar)
{
	ScalarType type;
	static void (*converter[])(const std::string& scalar) =
		{&ScalarConverter::convertFromChar, &ScalarConverter::convertFromInt,
		&ScalarConverter::convertFromFloat, &ScalarConverter::convertFromDouble,
		&ScalarConverter::convertFromPseudo};

	if (scalar.empty() == true)
	{
		return ;
	}
	type = getScalarType(scalar);
	if (type == UNDEFINED)
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << "Please try again..." << std::endl;
		return ;
	}
	converter[type](scalar);
}
