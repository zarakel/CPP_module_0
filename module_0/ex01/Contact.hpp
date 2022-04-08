#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		int ID;

		Contact( void );
		~Contact( void );

		void	write_contact(std::string input, int i);
};

#endif
