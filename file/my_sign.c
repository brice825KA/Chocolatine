/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** my_getnbr
*/

#include "../include/my.h"

int my_sign(char const *dest)
{
    int sign = 1;
    char c;

    for (int i = 0; dest[i] != '\0'; i++) {
        c = dest[i];
        switch (c) {
            case '-':
                sign = -1;
                break;
            case '+':
                sign = 1;
                break;
        }
    }
    return sign;
}
