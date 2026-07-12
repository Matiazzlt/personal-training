#include <stdio.h>

void    ft_sort_in_tab(int *tab, int size)
{
    int     cursor;
    int     a;
    int     b;

    a = 0;
    cursor = 0;
    while (a < size)
    {
        b = a + 1;
        while (b < size)
        {
            if (tab[b] < tab[a])
            {
                cursor = tab[a];
                tab[a] = tab[b];
                tab[b] = cursor;
            }
            b++;
        }
        a++;
    }
}

int     main(void)
{
    int     tab[] = {13, 53, 23, 97, 64, 32};
    int     i;
    int     size;

    i = 0;
    size = 6;
    ft_sort_in_tab(tab, size);
        while (i < size)
    {
        printf("%d", tab[i]);
        i++;
    }
}