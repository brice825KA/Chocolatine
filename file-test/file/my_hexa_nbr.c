/*
** EPITECH PROJECT, 2025
** my_octal_nbr
** File description:
** my_octal_nbr
*/

#include "../include/my.h"

int hex_caracs(char *hex, int i)
{
    char boot[15] = "ABCDEF";

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

int my_hexa_nbr(int nb)
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
            hex_caracs(hex, i);
        else
            my_putchar(hex[i]);
    }
    return 0;
}
