#ifndef CONTACT_H
# define CONTACT_H
#include <iostream>

class Contact {
	private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string DarkSecrete;

	public:
	Contact();
	std::string getFisrtName(void);
	std::string getLastName(void);
	std::string geNickName(void);
	std::string getPhoneNumber(void);
	std::string getDarkSecrete(void);
	void setInfo(std::string firstName, std::string lastName, std::string nickName
			, std::string phoneNumber, std::string DarkSecrete);
};

#endif

