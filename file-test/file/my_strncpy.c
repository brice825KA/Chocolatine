/*
** EPITECH PROJECT, 2025
** npcpy
** File description:
** ncpy
*/
#include "../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int j = 0; j < n; j++) {
        dest[j] = src[j];
    }
    return dest;
}
