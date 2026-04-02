/*
** EPITECH PROJECT, 2025
** my_octal_nbr
** File description:
** my_octal_nbr
*/

#include "../include/my.h"

int my_octal_nbr(int nb)
{
    int i = 0;
    char oct[5];
    int l = 0;

    while (nb != 0) {
        oct[i] = nb % 8 + '0';
        nb = nb / 8;
        i++;
        l++;
    }
    for (i = l - 1; i >= 0; i--)
        my_putchar(oct[i]);
    return 0;
}
