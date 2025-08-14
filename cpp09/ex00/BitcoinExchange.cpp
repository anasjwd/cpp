#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
		fetchData();
}

BitcoinExchange::~BitcoinExchange(void)
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	data = other.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return ( *this );
	data = other.data;
	return ( *this );
}

bool BitcoinExchange::checkDateFormat(std::string& date) {
    std::stringstream ss(date);
    std::string fragment;
    int year, month, day;
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// year:
    if (!getline(ss, fragment, '-'))
        return ( false );
    if (fragment.size() != 4)
        return ( false );
    for (unsigned int i = 0; i < fragment.size(); i++) {
        if (fragment[i] < '0' || fragment[i] > '9')
            return ( false );
    }
    std::stringstream yearSS(fragment);
	yearSS >> year;
	if (yearSS.fail() || !yearSS.eof())
		return ( false );
    if (year < 2009)
        return ( false );

    // month:
    if (!getline(ss, fragment, '-'))
        return ( false );
    if (fragment.size() != 2)
        return ( false );
    std::stringstream monthSS(fragment);
    monthSS >> month;
    if (monthSS.fail() || !monthSS.eof())
        return ( false );
    if (month == 2) {
        bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (leap) daysInMonth[2] = 29;
    } 
	else if (month < 1 || month > 12)
        return ( false );

    // day:
    if (!getline(ss, fragment))
        return ( false );
    if (fragment.size() != 2)
        return ( false );
    std::stringstream daySS(fragment);
    daySS >> day;
    if (daySS.fail() || !daySS.eof())
        return ( false );
    if (day < 1 || day > daysInMonth[month])
        return ( false );

    // check for extra data:
    if (ss.rdbuf()->in_avail() != 0)
        return ( false );
    return ( true );
}

void BitcoinExchange::parseDBline(std::string& line, std::string& date,
		double& exchangeRate) {
	std::stringstream ss(line);
	if (!getline(ss, date, ','))
		throw CorruptedData();
	if (checkDateFormat(date) == false)
		throw CorruptedData();
	std::string holder;
	if (!getline(ss, holder))
		throw CorruptedData();
	std::stringstream exchangeRateSS(holder);
	exchangeRateSS >> exchangeRate;
	if (exchangeRateSS.fail() || !exchangeRateSS.eof())
		throw CorruptedData();
}

void BitcoinExchange::fetchData(void) {
	std::ifstream csvFile;
	csvFile.open("data.csv");
	if (csvFile.fail())
		throw DataFileOpeningFailure();
	std::string line;
	std::getline(csvFile, line);
	if (line != "date,exchange_rate")
	{
		csvFile.close();
		throw CorruptedData();
	}
	std::string date;
	double exchangeRate;
	while (std::getline(csvFile, line))
	{
		try {
			parseDBline(line, date, exchangeRate);
		}
		catch (std::exception& e)
		{
			csvFile.close();
			throw;
		}
		if (data.count(date) > 0) {
			csvFile.close();
			throw CorruptedData();
		}
		data[date] = exchangeRate;
	}
	csvFile.close();
}

bool BitcoinExchange::parseInputLine(const std::string& line, std::string& date,
		double& value) {
	std::stringstream ss(line);
	std::string frag;
	
	if (!getline(ss, frag, ' '))
	{
		std::cerr << "Error: bad input\n";
		return ( false );
	}
	if (checkDateFormat(frag) == false)
	{
		std::cerr << "Error: bad input => " << frag << std::endl;
		return ( false );
	}
	date = frag;

	if (!getline(ss, frag, ' ') || frag != "|")
	{
		std::cerr << "Error: bad input\n";
		return ( false );
	}

	if (!getline(ss, frag))
	{
		std::cerr << "Error: bad input\n";
		return ( false );
	}
	for (unsigned int i = 0; i < frag.size(); i++)
	{
		if ((frag[i] < '0' || frag[i] > '9') && frag[i] != '.' && frag[i] != '+' && frag[i] != '-')
		{
			std::cerr << "Error: bad input => " << frag << std::endl;
			return ( false );
		}
	}
	std::stringstream converter(frag);
	converter >> value;
	if (converter.fail() || converter.eof() == false)
	{
		std::cerr << "Error: bad input => " << frag << std::endl;
		return ( false );
	}
	if (value < 0)
	{
		std::cerr << "Error: not a positive number\n";
		return ( false );
	}
	else if (value == 1000)
	{
		for (unsigned int i = 0; i < frag.size(); i++) {
			if (frag[i] == '.') {
				std::cerr << "Error: too large number\n";
				return ( false );
			}
		}
	}
	else if (value > 1000)
	{
		std::cerr << "Error: too large number\n";
		return ( false );
	}
	return ( true );
}

void BitcoinExchange::calcBtcValues(char* inputFile) {
	std::ifstream input;
	input.open(inputFile);
	if (input.fail())
		throw InputFileOpeningFailure();
	std::string line;
	if (!std::getline(input, line) || line != "date | value")
	{
		input.close();
		throw CorruptedInput();
	}
	std::string date;
	double value;
	double btcValue;
	std::map<std::string, double>::iterator it;
	while (std::getline(input, line))
	{
		if (parseInputLine(line, date, value) == true)
		{
			it = data.find(date);
			if (it != data.end()) {
				btcValue = data[date] * value;
			}
			else {
				it = data.lower_bound(date);
				if (it == data.begin()) {
					btcValue = it->second * value;
				} else {
					--it;
					btcValue = it->second * value;
				}
			}
			std::cout << date << " => " << value << " = "
				<< btcValue << std::endl;
		}
	}
}

const char* BitcoinExchange::CorruptedData::what() const throw() {
	return ( "Error: Invalid DataBase data format" );
}

const char* BitcoinExchange::DataFileOpeningFailure::what() const throw() {
	return ( "Error: Failed to open date.csv file" );
}

const char* BitcoinExchange::CorruptedInput::what() const throw() {
	return ( "Error: Invalid input data format" );
}

const char* BitcoinExchange::InputFileOpeningFailure::what() const throw() {
	return ( "Error: Failed to open input file" );
}

