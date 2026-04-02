/*
** EPITECH PROJECT, 2026
** parsing of argument
** File description:
** parsing of argument
*/

#include "../include/my.h"

int count_word(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 32 && (i == 0 || str[i - 1] <= 32))
            count += 1;
    }
    return count + 1;
}

char **my_str_to_word_array(char *str)
{
    char **args = NULL;
    char *path = NULL;
    int i = 0;

    if (str != NULL && str[0] != '\0') {
        args = malloc(sizeof(char *) * (count_word(str) + 1));
    } else return NULL;
    args[count_word(str)] = NULL;
    path = strtok(str, " \t\n");
    for (i = 0; path != NULL; i++) {
        args[i] = my_strdup(path);
        path = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
    return args;
}
