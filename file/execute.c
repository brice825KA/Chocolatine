/*
** EPITECH PROJECT, 2026
** execute programm
** File description:
** execute program
*/

#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>

static void free_arg(char **arg, char *res)
{
    for (int i = 0; arg[i]; i += 1)
        free(arg[i]);
    free(arg);
    free(res);
}

void execute(shell_t *bash, char *com, char **env)
{
    char **new_arg = my_str_to_word_array(com);
    shell_t *path = bash;
    char *res = NULL;
    pid_t pid;

    if (error_arg(com, new_arg) == NULL)
        return;
    if (my_strcmp(new_arg[0], "cd") == 0) {
        cd_bultin(new_arg, env);
        return;
    }
    if (my_strcmp(new_arg[0], "setenv") == 0) {
        gest_setenv(env, new_arg);
        return;
    }
    res = exect(new_arg[0]);
    if (res == NULL)
        res = loop_function(path, new_arg, res);
    execut_fork(res, env, new_arg);
    free_arg(new_arg, res);
}

char *exect(char *str)
{
    char *s = NULL;

    if (my_strchr(str, '/') == 1) {
        if (access(str, F_OK | X_OK) == 0) {
            s = my_strdup(str);
            return s;
        }
    }
    return NULL;
}

void execut_fork(char *str, char **env, char **arg)
{
    pid_t pid;
    int status;

    if (str == NULL)
        my_printf("%s: Command not found.\n", arg[0]);
    else {
        pid = fork();
        if (pid == -1)
            perror("fork");
        if (pid == 0) {
            pid_function(str, env, arg);
        } else
            segfault(pid);
    }
}

void pid_function(char *str, char **env, char **arg)
{
    if (execve(str, arg, env) == -1)
        perror(str);
    exit(0);
}

char *loop_function(shell_t *path, char **new_arg, char *res)
{
    while (path != NULL) {
        res = search_command(path->pathname, new_arg[0]);
        if (res != NULL)
            break;
        path = path->next;
    }
    return res;
}

static void gest_setenv(char **env, char **new_arg)
{
    if (my_strcmp(new_arg[0], "setenv") == 0) {
        built_in_setenv(env, new_arg);
        return;
    }
}
