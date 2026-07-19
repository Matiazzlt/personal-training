#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int cursor;

    cursor = *a;
    *a = *b;
    *b = cursor;
}

int main(void)
{
    int az;
    int bz;

    az = 123;
    bz = 321;
    ft_swap(&az, &bz);
    printf("%d\n", az);
    printf("%d\n", bz);
}