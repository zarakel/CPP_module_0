#include <iostream>
#include <string>

int	main(int argc,  char **argv)
{
	int		i;
	std::string	str;

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		
		while (i < argc)
			str += argv[i++];
		i = 0;
		while (str[i])
		{
			if (str[i] >= 97 && str[i] <= 122 )
				str[i] -= 32;
			i++;
		}
		std::cout << str << std::endl;
	}
	return (0);
}
