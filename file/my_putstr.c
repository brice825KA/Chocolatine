/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** my_putstr
*/

#include "../include/my.h"

int my_putstr(char const *src)
{
    if (src == NULL)
        return 0;
    for (int i = 0; src[i] != '\0'; i++)
        my_putchar(src[i]);
    return 0;
}
