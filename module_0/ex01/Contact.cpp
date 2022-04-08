#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Constructor called" << std::endl;
	return;
}


Contact::~Contact(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Contact::write_contact(std::string input, int i)
{

	if (i == 0)
	{
		first_name = input;
		std::cout << "First name have been added" << std::endl;
	}
	if (i == 1)
	{
		last_name = input;
		std::cout << "Last name have been added" << std::endl;
	}
	if (i == 2)
	{
		nickname = input;
		std::cout << "Nickname have been added" << std::endl;
	}
	if (i == 3)
	{
		phone_number = input;
		std::cout << "Phone number have been added" << std::endl;
	}
	if (i == 4)
	{
		darkest_secret = input;
		std::cout << "Darkest secret have been added" << std::endl;
	}
	return;
}
