/*
** EPITECH PROJECT, 2026
** my strchar
** File description:
** my strchar
*/

#include "../include/my.h"

int my_strchr(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            count = 1;
    }
    return count;
}
