/*
** EPITECH PROJECT, 2025
** strcmp
** File description:
** strcmp
*/

#include "../include/my.h"

int my_strcmp(char const *dest, char const *str)
{
    int i = 0;

    while (dest[i] != '\0' && str[i] != '\0') {
        if (dest[i] != str[i])
            return dest[i] - str[i];
        i++;
    }
    return dest[i] - str[i];
}
