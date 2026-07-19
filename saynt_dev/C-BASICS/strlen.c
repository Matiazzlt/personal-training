#include <stdio.h>

int ft_strlen(char *str)
{
    char    count;

    count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return (count);
}

int main(void)
{
    char str[] = "la vie est longue ptn je sais pas combien de catacteres j'ecris la par contre";
    int lenght;

    lenght = ft_strlen(str);
    printf("%d\n", lenght);
}