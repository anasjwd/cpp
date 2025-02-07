#pragma once
# include <string>

class Contact {
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	DarkestSecret;

	public:
		std::string	GetFirstName(void);
		std::string	GetLastName(void);
		std::string	GetNickName(void);
		std::string	GetPhoneNumber(void);
		std::string	GetDarkestSecret(void);

		void	SetFirstName(std::string _FirstName);
		void	SetLastName(std::string _LastName);
		void	SetNickName(std::string _NickName);
		void	SetPhoneNumber(std::string _PhoneNumber);
		void	SetDarkestSecret(std::string _DarkestSecret);
};
