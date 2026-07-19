#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (nb < 0)
	{
		putchar('-');
		nb = -nb;
	}
	if (nb >= 0 && nb < 9)
	{
		putchar(nb + '0');
	}
	else
	{ 
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
}

int	main(void)
{
	putnbr(-5);
	putnbr(5);
	putnbr(0);
	putnbr(-2147483648);
}