#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>

bool	CheckInput(std::string input, int (CheckerFunc)(int))
{
	int	length;
	
	length = input.length();
	if (input.empty())
	{
		std::cout << "Invalid input, try again" << std::endl;
		return 1;
	}
	for (int i = 0; i < length; i++)
	{
		if (CheckerFunc(input[i]) == false)
		{
			std::cout << "Invalid input, try again" << std::endl;
			return 1;
		}
	}
	return 0;
}

bool	GetInput(std::string& input) 
{
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << "exit" << std::endl;
		return 1;
	}
	std::cin.clear();
	return 0;
}

bool	AddContact(Contact &contact) {
	std::string	input;

	do {
		std::cout << "Enter first name: ";
		if (GetInput(input))
			return 1;
	} while (CheckInput(input, std::isalpha));
	contact.SetFirstName(input);
	do {
		std::cout << "Enter last name: ";
		if (GetInput(input))
			return 1;
	} while (CheckInput(input, std::isalpha));
	contact.SetLastName(input);
	do {
		std::cout << "Enter nickname: ";
		if (GetInput(input))
			return 1;
	} while (CheckInput(input, std::isalnum));
	contact.SetNickName(input);
	do {
		std::cout << "Enter phone number: ";
		if (GetInput(input))
			return 1;
	} while (CheckInput(input, std::isdigit));
	contact.SetPhoneNumber(input);
	do {
		std::cout << "Enter darkest secret: ";
		if (GetInput(input))
			return 1;
	} while (CheckInput(input, std::isprint));
	contact.SetDarkestSecret(input);
	return 0;
}

void	PrintColumn(std::string output)
{
	if (output.length() > 10)
	{
		output.at(10) = '.';
		output.at(11) = '\0';
	}
	if (output.length() <= 10)
		std::cout << std::setw(10) << output;
	else
	{
		output.at(9) = '.';
		std::cout << std::setw(10) << output.substr(0, 10);
	}
}

void	DisplayContacts(PhoneBook phonebook)
{
	for (int i = 0; i < 8; i++)
	{
		if (phonebook.GetContact(i).GetFirstName().empty())
			return ;
		std::cout << std::setw(10) << i;
		std::cout << "|";
		PrintColumn(phonebook.GetContact(i).GetFirstName());
		std::cout << "|";
		PrintColumn(phonebook.GetContact(i).GetLastName());
		std::cout << "|";
		PrintColumn(phonebook.GetContact(i).GetNickName());
		std::cout << std::endl;
	}
}

int	CheckNumber(std::string input)
{
	size_t	idx;

	if (input.empty())
	{
		std::cout << "Invalid index, try again" << std::endl;
		return 1;
	}
	idx = 0;
	while (input[idx] == ' ')
		idx++;
	while (input[idx] && input[idx] != ' ')
	{
		if (!(std::isdigit(input[idx])))
		{
			std::cout << "Invalid index, try again" << std::endl;
			return 1;
		}
		idx++;
	}
	while (input[idx] == ' ')
		idx++;
	if (idx != input.length())
		return 1;
	return 0;
}

bool	DisplayEntry(PhoneBook phonebook)
{
	std::string			input;
	int					idx;
	std::stringstream	ss;

	start:
	do {
		std::cout << "Enter entry's index: ";
		if (GetInput(input))
			return 1;
	} while (CheckNumber(input));
	ss << input;
	ss >> idx;
	if (idx < 0 || idx > 7 || phonebook.GetContact(idx).GetFirstName().empty())
	{
		std::cout << "Invalid entry, try again" << std::endl;
		ss.clear();
		goto start;
	}
	std::cout << "First name: ";
	std::cout << phonebook.GetContact(idx).GetFirstName() << std::endl;
	std::cout << "Last name: ";
	std::cout << phonebook.GetContact(idx).GetLastName() << std::endl;
	std::cout << "Nickname: ";
	std::cout << phonebook.GetContact(idx).GetNickName() << std::endl;
	std::cout << "Phone number: ";
	std::cout << phonebook.GetContact(idx).GetPhoneNumber() << std::endl;
	std::cout << "Darkest secret: ";
	std::cout << phonebook.GetContact(idx).GetDarkestSecret() << std::endl;
	return 0;
}

int	main(void) {
	PhoneBook	phonebook;
	Contact		contact;
	std::string	input;
	int			idx;

	idx = 0;
	while (true)
	{
		std::cout << "Enter a command: ";
		if (GetInput(input))
			return 1;
		if (input == "ADD")
		{
			if (AddContact(phonebook.GetContact(idx)))
				return 0;
			idx = (idx + 1) % 8;
		}
		else if (input == "SEARCH")
		{
			if (phonebook.GetContact(0).GetFirstName().empty())
			{
				std::cout << "No saved contact available, "
					<< "add a contact to see it here" << std::endl;
				continue ;
			}
			DisplayContacts(phonebook);
			if (DisplayEntry(phonebook))
				return 0;
		}
		else if (input == "EXIT")
			return 0;
	}
}
