/*
** EPITECH PROJECT, 2026
** my concat params
** File description:
** my params
*/

#include "../include/my.h"

char *my_concat_params(char *s1, char *s2)
{
    int lenght = my_strlen(s1) + my_strlen(s2);
    int len = my_strlen(s1);
    int nb = (s1[len - 1] == '/') ? 0 : 1;
    char *dest = malloc(sizeof(char) * (lenght + nb + 1));
    int k = 0;

    if (s1 == NULL || s2 == NULL)
        return NULL;
    my_strcpy(dest, s1);
    if (nb) {
        dest[len] = '/';
        len += 1;
    }
    while (s2[k] != '\0') {
        dest[len] = s2[k];
        k += 1;
        len += 1;
    }
    dest[len] = '\0';
    return dest;
}
