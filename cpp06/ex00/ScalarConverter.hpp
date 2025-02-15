#pragma once
#include <string>

class ScalarConverter {
	private:
		ScalarConverter(void);
		static void convertChar(const std::string scalar);
		static void convertInt(const std::string scalar);
		static void convertFloat(const std::string scalar);
		static void convertDouble(const std::string scalar);
	public:
		static void convert(const std::string& scalar);
};
