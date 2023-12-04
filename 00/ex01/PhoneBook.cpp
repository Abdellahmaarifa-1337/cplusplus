#include "main.hpp"

PhoneBook::PhoneBook()
{
	this->currentIndex = 0;
	this->length = 0;
	this->size = 8;
};

void PhoneBook::addNewContact(std::string firstName, std::string lastName, std::string nickName
		, std::string phoneNumber, std::string DarkSecrete)
{
	if (length >= size)
		currentIndex = 0;
	else
		length++;
	(contacts[currentIndex]).setInfo(firstName, lastName, nickName, phoneNumber, DarkSecrete);
	currentIndex++;
};

std::string trunc_str(std::string str)
{
	str = str.substr(0, 10);
	if (str.length() == 10)
		str[9] = '.';
	return (str);
}
void PhoneBook::getContact()
{
	int i;
	int in;
	std::string num;

	i = 0;

	if (length == 0)
	{
		COUT << "Try to enter a contact first!\n";
		return ;
	}
	while (i < length)
	{
		std::string a;

		COUT << std::setw(10) << i << "|";

		COUT << std::setw(10) << trunc_str((contacts[i]).getFisrtName()) << "|";

		COUT << std::setw(10) << trunc_str((contacts[i]).getLastName()) << "|";
		COUT << std::setw(10) <<  trunc_str((contacts[i]).geNickName()) << "|" << ENDL;
		i++;
	}
	

	COUT << "Enter an index : " << ENDL;
	get_number(num);
	std::stringstream(num) >> in;
	if (in >= length)
		COUT << "OUT OF RANGE!" << ENDL;
	else
	{
		COUT << "First name   : " <<  (contacts[in]).getFisrtName() << ENDL;
		COUT << "Last name    : " <<  (contacts[in]).getLastName() << ENDL;
		COUT << "Nick name    : " <<  (contacts[in]).geNickName() << ENDL;
		COUT << "Phone Number : " <<  (contacts[in]).getPhoneNumber() << ENDL;
		COUT << "Dark Secrete : " <<  (contacts[in]).getDarkSecrete() << ENDL;
	}

};