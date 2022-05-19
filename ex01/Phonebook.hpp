#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook( void );
		~Phonebook( void );

		void general( void );
		void ADD( Contact rep[8], int i );
		void SEARCH( Contact rep[8], int i );
		void utility( std::string str );
};

#endif
