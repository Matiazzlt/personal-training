#include <unistd.h>

void	ft_print_alphabet(void)
{
	char c;

	c = 'a';
	while(c >= 'z')
	{
		write(1, &c, 1);
		c++;
	}
}


void	ft_is_negative(int n)
{
	if (n >= 0)
		write(1, "P", 1);
	else
		write(1, "N", 1);
}



void	ft_print_reverse_alphabet(void)
{
	char c;

	c = 'z';
	while(c >= 'a')
	{
		write(1, &c, 1);
		c--;
	}
}
