/*
** EPITECH PROJECT, 2026
** multiarg file
** File description:
** multi arg file
*/

#include "../include/my.h"

int count_word_lim(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i]; i += 1) {
        if (str[i] == c)
            count += 1;
    }
    return count;
}

char **multi_arg(char *str)
{
    char *past = NULL;
    char *copy = my_strdup(str);
    int count = count_word_lim(str, ';');
    char **argv = malloc(sizeof(char *) * (count + 2));
    int i = 0;

    past = strtok(copy, ";\n");
    while (past) {
        argv[i] = my_strdup(past);
        past = strtok(NULL, ";\n");
        i += 1;
    }
    free(copy);
    argv[i] = NULL;
    return argv;
}
