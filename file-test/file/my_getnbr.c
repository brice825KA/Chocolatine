/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** my_getnbr
*/

#include "../include/my.h"

int my_getnbr(char const *str)
{
    int n = 0;
    int sign = my_sign(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 48 && str[i] <= 59) {
            n = n * 10 + str[i] - 48;
        }
    }
    my_printf("%d", n * sign);
    return n * sign;
}
