#include <unistd.h>

char *ft_rev_print(char *str)
{
    int i;
    int last;

    i = 0;
    while (str[i] != '\0')
        i++;
    last = i - 1;    
    while (last >= 0)
    {
        write(1, &str[last], 1);
        last--;
    }
    write(1, "\n", 1);
    return (str);
}

int main(void)
{
    char str[] = "12345";

    ft_rev_print(str);
}