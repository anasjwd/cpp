#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact	&PhoneBook::GetContact(int index)
{
	return (contacts[index]);
};
