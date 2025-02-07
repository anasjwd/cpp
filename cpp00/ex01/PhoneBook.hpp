#pragma once
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
	public:
		Contact	&GetContact(int index);
};
