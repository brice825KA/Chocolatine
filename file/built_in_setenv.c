/*
** EPITECH PROJECT, 2026
** built in setenv
** File description:
** built in setenv
*/

#include "../include/my.h"

char **built_in_setenv(char **env, char **args)
{
    char **new_env;

    if (!args[1] || !args[2]) {
        print_env(env);
        return env;
    }
    new_env = copy_env(env);
    return new_env;
}

char **copy_env(char **env)
{
    char **new_env = NULL;
    int count = 0;
    int i = 0;
    int j = 0;

    while (env[j] != NULL) {
        count += 1;
        j += 1;
    }
    new_env = malloc(sizeof(char *) * (count + 2));
    while (env[i] != NULL) {
        new_env[i] = my_strdup(env[i]);
        i += 1;
    }
    new_env[i] = NULL;
    return new_env;
}

void print_env(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        my_printf("%s\n", env[i]);
        i += 1;
    }
}

void free_env(char **new_env)
{
    int j = 0;

    while (new_env[j]) {
        free(new_env[j]);
        j += 1;
    }
    free(new_env);
}
