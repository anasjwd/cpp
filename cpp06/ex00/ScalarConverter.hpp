#pragma once
#include <string>

enum ScalarType {CHAR, INT, FLOAT, DOUBLE, PSEUDO, UNDEFINED};

class ScalarConverter {
	private:
		static char charScalar;
		static int intScalar;
		static float floatScalar;
		static double doubleScalar;
		ScalarConverter(void);
		static void convertFromChar(const std::string& scalar);
		static void convertFromInt(const std::string& scalar);
		static void convertFromFloat(const std::string& scalar);
		static void convertFromDouble(const std::string& scalar);
		static void convertFromPseudo(const std::string& scalar);
		static ScalarType getScalarType(const std::string& scalar);
		static bool isChar(const std::string& scalar);
		static bool isInt(const std::string& scalar);
		static bool isFloat(const std::string& scalar);
		static bool isDouble(const std::string& scalar);
		static bool isPseudo(const std::string& scalar);
		static void printConversions(double givenValue);
	public:
		static void convert(const std::string& scalar);
};
