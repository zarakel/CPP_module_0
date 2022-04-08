#include <iostream>
#include <string>
#include <iomanip>
#include "Phonebook.hpp"

Phonebook::Phonebook( void )
{
	std::cout << "Constructor called" << std::endl;
	return;
}


Phonebook::~Phonebook( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Phonebook::general( void )
{
	std::string	input;
	Contact	rep[7];
	int		i;

	i = 0;
	while (1)
	{
		rep[i].ID = 0;
		std::cout << "Put your input : ";
		std::getline (std::cin, input);
		std::string str1 (input);
		std::string str2 ("ADD");
		std::string str3 ("SEARCH");
		std::cout << std::endl;
		if (str1.compare(str2) == 0)
		{
			ADD(rep, i);
			i++;
			input.clear();
		}
		else if (str1.compare(str3) == 0 && i >= 1)
		{
			SEARCH(rep, i);
			input.clear();
		}
	/*	else if (input == "EXIT")
		{
			EXIT;
		}*/
		else
		{
			std::cout << "FADA" << std::endl;
			input.clear();
		}
		if (i >= 7)
			i = 0;
	}
}

void	Phonebook::ADD(Contact rep[7], int i )
{
	std::string	input;
	int		j;
	
	j = 0;
	while (j < 5)
	{
		std::cout << " Put your contact informations : ";
		std::getline (std::cin, input);
		std::cout << std::endl;
		if (input.empty() == 0)
		{
			rep[i].write_contact(input, j);
			rep[i].ID = i;
			j++;
		}
	}
	return;
}

void	Phonebook::SEARCH(Contact rep[7], int i )
{
	std::string input;
	int y;
	
	y = 0;	
	while(y <= rep[i - 1].ID)
	{
		std::cout << rep[y].ID << "         | ";
		Phonebook::utility(rep[y].first_name);
		Phonebook::utility(rep[y].last_name);
		Phonebook::utility(rep[y].nickname);
		std::cout << std::endl;
		y++;
	}
	std::cout << " Put your ID search : ";
	//std::cin >> input;
	std::getline (std::cin, input);
	std::cout << std::endl;
	if (input < "0" || input > "9")
		std::cout << "ERREUR DE SAISIE" << std::endl;
	input.clear();
	return;
}

void	Phonebook::utility(std::string str)
{
	int i;

	i = str.size();
	if (i < 10)
	{
		std::cout << str;
		while(i < 10)
		{
			std::cout << " ";
			i++;
		}
	}
	else if (i > 10)
	{
		str.resize(9);
		str += '.';
		std::cout << str;
	}
	std::cout << " | ";
}
