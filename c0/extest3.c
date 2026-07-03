#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int modulo;
	int divid;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		modulo = nb % 10;
		divid = nb / 10;
		ft_putnbr(divid);
	}
	if (nb > 9)
		ft_putchar(modulo + '0');
	else
		ft_putchar(nb + '0');
}

int	main(void)
{
	ft_putnbr(9);
	ft_putnbr(-2147483648);
	ft_putnbr(-390);
}
