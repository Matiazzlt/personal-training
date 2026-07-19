#include <unistd.h>

void    putchar(char c)
{
    write(1, &c, 1);
}

void    putnbr(int n)
{
    if (n < 0)
    { 
        putchar('-');
        n = -n;
    }
	if (n >= 0 && n < 10)
		putchar(n + '0');
	else
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
}

int main(void)
{
    putnbr(34);
    putnbr(-345);
    putnbr(4);
    putnbr(34);
}