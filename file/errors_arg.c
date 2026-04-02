/*
** EPITECH PROJECT, 2026
** error arg
** File description:
** error arg
*/

#include "../include/my.h"

char *error_arg(char *com, char **new_arg)
{
    if (com == NULL)
        return NULL;
    if (new_arg == NULL || new_arg[0] == NULL || new_arg[0][0] == '\0')
        return NULL;
    return "CORRECT";
}
