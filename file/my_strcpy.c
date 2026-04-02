/*
** EPITECH PROJECT, 2025
** my_strcpy
** File description:
** my_strcpy
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int j = 0;
    int l = my_strlen(src);

    for (j = 0; src[j] != '\0'; j++) {
        dest[j] = src[j];
    }
    dest[j] = '\0';
    return dest;
}
