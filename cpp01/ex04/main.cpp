#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string	*addExtension(std::string filename, std::string ext)
{
	std::string	*repFileName;

	repFileName = new std::string(filename + ext);
	return repFileName;
}

bool	openFiles(char *fileName, std::ifstream& file,
		std::ofstream& repFile)
{
	std::string	*repFileName;

	file.open(fileName);
	if (file.fail()) {
		std::cout << "Failed: unable to open the file: " << fileName
			<< std::endl;
		std::cout << "Please try again" << std::endl;
		return 1;
	}
	repFileName = addExtension(fileName, ".replace");
	repFile.open(repFileName->c_str());
	if (file.fail()) {
		std::cout << "Failed: unable to open the file: " << repFileName
			<< std::endl;
		std::cout << "Please try again" << std::endl;
		file.close();
		delete repFileName;
		return 1;
	}
	delete repFileName;
	return 0;
}

std::string	*doReplacement(const std::string readBuf, const std::string toReplace,
		const std::string replacement)
{
	unsigned long	pos = 0;
	std::string		result(readBuf);

	pos = result.find(toReplace);
	while (pos != std::string::npos)
	{
		result = result.substr(0, pos) + replacement
			+ result.substr(pos + toReplace.length(), result.length());
		pos = result.find(toReplace);
	}
	return ( new std::string(result) );
}

int	main(int ac, char **av)
{
	std::ifstream		file;
	std::ofstream		repFile;
	std::string			readBuf;
	std::string			repFileName;
	std::string			*result;
	std::stringstream	buffer;

	if (ac != 4) {
		std::cout << "Invalid: Number of arguments is incorrect!" << std::endl;
		std::cout << "Valid format: ./Program <filename> toreplace replacement"
			<< std::endl;
		return 1;
	}
	if (openFiles(av[1], file, repFile))
		return 1;
	buffer << file.rdbuf();
	readBuf = buffer.str();
	if (readBuf.empty())
		return 0;
	result = doReplacement(readBuf, av[2], av[3]);
	repFile << result->c_str();
	delete result;
	file.close();
	repFile.close();
	return 0;
}
