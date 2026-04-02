/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** my_strdup
*/

#include "../include/my.h"

char *my_strdup(char const *src)
{
    int j = my_strlen(src);
    char *dest = malloc(sizeof(char) * (j + 1));

    if (dest == NULL)
        return NULL;
    my_strcpy(dest, src);
    return dest;
}
