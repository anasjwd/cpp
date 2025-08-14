#pragma once

#include <string>
#include <map>
#include <iostream>
#include <exception>
#include <sstream>
#include <fstream>

class BitcoinExchange {
	private:
		std::map<std::string, double> data;

	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void fetchData(void);
		void parseDBline(std::string& line, std::string& date, double& exchangeRate);
		bool checkDateFormat(std::string& date);
		void calcBtcValues(char* inputFile);
		bool parseInputLine(const std::string& line, std::string& date, double& value);

		class CorruptedData : public std::exception {
			public:
				const char* what() const throw();
		};
		class DataFileOpeningFailure : public std::exception {
			public:
				const char* what() const throw();
		};
		class CorruptedInput : public std::exception {
			public:
				const char* what() const throw();
		};
		class InputFileOpeningFailure : public std::exception {
			public:
				const char* what() const throw();
		};
};

