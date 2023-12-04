#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
#include "Contact.hpp"
#include <iostream>

class PhoneBook {
	private:
	Contact contacts[8];
	int currentIndex;
	int size;
	int length;

	public:
	PhoneBook();
	void addNewContact(std::string firstName, std::string lastName, std::string nickName
			, std::string phoneNumber, std::string DarkSecrete);
	void getContact();
};

#endif