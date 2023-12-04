#include "main.hpp"

Contact::Contact()
{
	firstName = "";
	lastName  = "";
	nickName = "";
	phoneNumber = "";
	DarkSecrete = "";
};

std::string Contact::getFisrtName(void)
{
	return (firstName);
};

std::string Contact::getLastName(void)
{
	return (lastName);
};

std::string Contact::geNickName(void)
{
	return (nickName);
};

std::string Contact::getPhoneNumber(void)
{
	return (phoneNumber);
};

std::string Contact::getDarkSecrete(void)
{
	return (DarkSecrete);
};

void	Contact::setInfo(std::string firstName, std::string lastName, std::string nickName
			, std::string phoneNumber, std::string DarkSecrete)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->DarkSecrete = DarkSecrete;
};
