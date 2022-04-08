#include <iostream>

int	main(int argc,  char **argv)
{
	int i;
	char *str;

	i = 0;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		str = argv[1];
		while(str[i])
		{
			if (str[i] >= 97 && str[i] <= 122 )
				str[i] -= 32;
			i++;
		}
		std::cout << str << std::endl;
	}
	return (0);
}
