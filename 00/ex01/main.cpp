#include "main.hpp"
#include <iostream>
#include <sstream>


int main(void)
{
	PhoneBook phonebook;
	std::string cmd;
	
	while (1)
	{
		COUT << "RUN a CMD : " << ENDL;
		get_string(cmd);
		if (cmd == "EXIT")
			exit(0);
		if (cmd == "ADD")
		{
			std::string firstName;
			std::string lastName;
			std::string nickName;
			std::string phoneNumber;
			std::string DarkSecrete;

			COUT << "First name : " << ENDL;
			get_string(firstName);
			COUT << "Last name : " << ENDL;
			get_string(lastName);
			COUT << "Nick name : " << ENDL;
			get_string(nickName);
			COUT << "Phone number : " << ENDL;
			get_number(phoneNumber);
			COUT << "Darkest Secert: " << ENDL;
			get_string(DarkSecrete);
			phonebook.addNewContact(firstName, lastName, nickName
				, phoneNumber, DarkSecrete);
		}
		if (cmd == "SEARCH")
		{
			phonebook.getContact();
		}
	}
	return (0);
}