/*
** EPITECH PROJECT, 2026
** function exit
** File description:
** function exit
*/

#include "../include/my.h"

int func_exit(char *str)
{
    if (str[my_strlen(str) - 1] == '\n')
        str[my_strlen(str) - 1] = '\0';
    if (my_strcmp(str, "exit") == 0)
        return (0);
    return 1;
}
