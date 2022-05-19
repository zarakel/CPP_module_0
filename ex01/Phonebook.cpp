#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
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
	Contact		rep[8];
	int		i;
	int		lock;

	i = 0;
	lock = 0;
	rep[i].ID = 0;
	while ( 1 )
	{
		std::cout << "Put your input : ";
		std::getline ( std::cin, input );
		std::string str1 ( input );
		std::string str2 ( "ADD" );
		std::string str3 ( "SEARCH" );
		std::string str4 ( "EXIT" );
		std::cout << std::endl;
		if ( str1.compare( str2 ) == 0 )
		{
			ADD( rep, i );
			i++;
			input.clear();
		}
		else if ( str1.compare( str3 ) == 0 && (i >= 1 || lock == 8))
		{
			if (lock == 8)
				SEARCH( rep, lock );
			else 
				SEARCH( rep, i );
			input.clear();
		}
		else if ( str1.compare( str4 ) == 0 )
			exit( 1 );
		if ( i >= 8 )
		{
			i = 0;
			lock = 8;
		}
	}
}

void	Phonebook::ADD( Contact rep[8], int i )
{
	std::string	input;
	int		j;
	
	j = 0;
	std::string str1 ( "EXIT" );
	while ( j < 5 )
	{
		std::cout << " Put your contact informations : ";
		std::getline ( std::cin, input );
		std::cout << std::endl;
		if ( input.compare( str1 ) == 0 )
			exit(1);
		if ( input.empty() == 0 )
		{
			rep[i].write_contact( input, j );
			rep[i].ID = i;
			j++;
		}
	}
	return;
}

void	Phonebook::SEARCH( Contact rep[8], int i )
{
	std::string input;
	int y;
	
	y = 0;	
	std::string str1 ( "EXIT" );
	while( y <= rep[i - 1].ID )
	{
		std::cout << rep[y].ID << "         | ";
		Phonebook::utility( rep[y].first_name );
		Phonebook::utility( rep[y].last_name );
		Phonebook::utility( rep[y].nickname );
		std::cout << std::endl;
		y++;
	}
	std::cout << " Put your ID search : ";
	std::getline ( std::cin, input );
	std::cout << std::endl;
	if ( input.compare( str1 ) == 0 )
		exit( 1 );
	if ( input < "0" || input > "7" )
		std::cout << "ERREUR DE SAISIE" << std::endl;
	else
	{
		y = (int)input[0] - '0';
		std::cout << rep[y].first_name << std::endl;
		std::cout << rep[y].last_name << std::endl;
		std::cout << rep[y].nickname << std::endl;
		std::cout << rep[y].phone_number << std::endl;
		std::cout << rep[y].darkest_secret << std::endl;
	}
	input.clear();
	return;
}

void	Phonebook::utility( std::string str )
{
	int i;

	i = str.size();
	if ( i < 10 )
	{
		std::cout << str;
		while( i < 10 )
		{
			std::cout << " ";
			i++;
		}
	}
	else if ( i > 10 )
	{
		str.resize( 9 );
		str += '.';
		std::cout << str;
	}
	std::cout << " | ";
}
