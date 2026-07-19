#include <stdio.h>

void    ft_rev_int_tab(int *tab, int size)
{
    int     cursor;
    int     start;
    int     end;

    start = 0;
    end = size - 1;
    while (start < end)
    {
        cursor = tab[start];
        tab[start] = tab[end];
        tab[end] = cursor;
        start++;
        end--;
    }
}

int     main(void)
{
    int     string[] = {1, 2, 3, 4, 5, 6, 7};
    int     size;
    int     i;

    i = 0;
    size = 7;
    ft_rev_int_tab(string, size);
    while (i < size)
    {
        printf("%d", string[i]);
        i++;
    }
    return (0);
}