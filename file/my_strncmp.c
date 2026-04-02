/*
** EPITECH PROJECT, 2026
** my strcnmp
** File description:
** my strcnmp
*/

#include "../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int cmp = 0;

    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            cmp = s1[i] - s2[i];
            break;
        }
    }
    return cmp;
}
