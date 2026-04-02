/*
** EPITECH PROJECT, 2025
** my_hexax_nbr
** File description:
** my_hexax_nbr
*/

#include "../include/my.h"

int hex_carac(char *hex, int i)
{
    char boot[15] = "abcdef";

    for (int i = 0; boot[i] != '\0'; i++) {
        if (hex[i] == 58)
            my_putchar(boot[0]);
        if (hex[i] == 59)
            my_putchar(boot[1]);
        if (hex[i] == 60)
            my_putchar(boot[2]);
        if (hex[i] == 61)
            my_putchar(boot[3]);
        if (hex[i] == 62)
            my_putchar(boot[4]);
        if (hex[i] == 63)
            my_putchar(boot[5]);
    }
    return 0;
}

int my_hexax_nbr(int nb)
{
    int i = 0;
    char hex[5];
    int l;

    while (nb != 0) {
        hex[i] = nb % 16 + '0';
        nb = nb / 16;
        i++;
        l++;
    }
    for (i = l - 1; i >= 0; i--) {
        if (hex[i] >= 58 && hex[i] <= 63)
            hex_carac(hex, i);
        else
            my_putchar(hex[i]);
    }
    return 0;
}
