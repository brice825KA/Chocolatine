/*
** EPITECH PROJECT, 2025
** revstr
** File description:
** revstr
*/

#include "../include/my.h"

char *my_revstr(char *str)
{
    int i;
    int l;

    l = my_strlen(str);
    for (i = l - 1; i >= 0; i--)
        my_putchar(str[i]);
    return &str[i];
}
