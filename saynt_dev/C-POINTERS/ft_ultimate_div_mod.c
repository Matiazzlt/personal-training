#include <stdio.h>

void    ft_ultimate_div_mod(int *a, int *b)
{
    int     div;
    int     mod;

    div = *a / *b;
    mod = *a % *b;

    *a = div;
    *b = mod;
}

int    main(void)
{
    int     az;
    int     bz;

    az = 42;
    bz = 5;
    ft_ultimate_div_mod(&az, &bz);
    printf("%d\n", az);
    printf("%d\n", bz);
}