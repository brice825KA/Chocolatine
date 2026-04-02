/*
** EPITECH PROJECT, 2026
** search command
** File description:
** search command
*/

#include "../include/my.h"

char *search_command(char *path, char *command)
{
    char *new_path = my_concat_params(path, command);

    if (!new_path)
        return NULL;
    if (access(new_path, F_OK | X_OK) == 0)
        return new_path;
    free(new_path);
    return NULL;
}
