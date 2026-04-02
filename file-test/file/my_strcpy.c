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

    for (j = l - 1; src[j] != '\0'; j++) {
        dest = malloc(sizeof(char) * (j + 1));
        dest[j] = src[j];
        my_putchar(dest[j]);
    }
    return dest;
}
