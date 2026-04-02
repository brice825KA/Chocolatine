/*
** EPITECH PROJECT, 2025
** string up case
** File description:
** string up case
*/

#include "../include/my.h"

int string_upcase(char *sente)
{
    int k = 0;
    int lenght = my_strlen(sente);

    for (int i = 0; sente[i] != '\0'; i++) {
        if (sente[i] >= 'A' && sente[i] <= 'Z')
            return 1;
    }
    return 0;
}
