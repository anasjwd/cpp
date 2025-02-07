#include "Contact.hpp"

std::string	Contact::GetFirstName(void) {
	return (FirstName);
}

std::string	Contact::GetLastName(void) {
	return (LastName);
}

std::string	Contact::GetNickName(void) {
	return (NickName);
}

std::string	Contact::GetPhoneNumber(void) {
	return (PhoneNumber);
}

std::string	Contact::GetDarkestSecret(void) {
	return (DarkestSecret);
}

void	Contact::SetFirstName(std::string _FirstName) {
	FirstName = _FirstName;
}

void	Contact::SetLastName(std::string _LastName) {
	LastName = _LastName;
}

void	Contact::SetNickName(std::string _NickName) {
	NickName = _NickName;
}

void	Contact::SetPhoneNumber(std::string _PhoneNumber) {
	PhoneNumber = _PhoneNumber;
}

void	Contact::SetDarkestSecret(std::string _DarkestSecret) {
	DarkestSecret = _DarkestSecret;
}
