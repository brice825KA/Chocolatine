/*
** EPITECH PROJECT, 2026
** parsing file
** File description:
** parsing file
*/

#include "../include/my.h"

shell_t *new_str_to_word(char *str_or)
{
    char *new_str = my_strdup(&str_or[5]);
    shell_t *tcsh = NULL;
    shell_t *zsh = NULL;
    char *path;
    int k = 0;

    path = strtok(new_str, ":");
    while (path != NULL) {
        zsh = malloc(sizeof(shell_t));
        zsh->pathname = my_strdup(path);
        zsh->next = tcsh;
        tcsh = zsh;
        path = strtok(NULL, ":");
    }
    free(new_str);
    return tcsh;
}
