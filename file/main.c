/*
** EPITECH PROJECT, 2026
** main
** File description:
** main
*/

#include "../include/my.h"

static void value_default(shell_t **bash, char **user, char *new_e)
{
    *bash = (new_e != NULL) ? new_str_to_word(new_e) :
        new_str_to_word("PATH=/bin:/usr/bin");
    *user = (!*user) ? my_strdup("guest") : *user;
}

static void free_allocation(shell_t *bash, char *new, char *user)
{
    shell_t *tmp;

    while (bash != NULL) {
        tmp = bash->next;
        free(bash->pathname);
        free(bash);
        bash = tmp;
    }
    free(new);
    free(user);
}

void execute_multi(char *sent, char **env, shell_t *bash)
{
    char **ar = multi_arg(sent);

    for (int i = 0; ar[i]; i += 1) {
        execute(bash, ar[i], env);
        free(ar[i]);
    }
    free(ar);
}

int main(int argc, char **argv, char **env)
{
    char *new = NULL;
    size_t len = 0;
    shell_t *bash;
    char *new_e = NULL;
    char *user = name(env);

    new_e = new_env(env);
    value_default(&bash, &user, new_e);
    while (1) {
        if (isatty(0))
            my_printf("\033[1;3;4;34m[ << %s >> ]\033[0m ", user);
        if (getline(&new, &len, stdin) == -1 || func_exit(new) == 0)
            break;
        if (my_strchr(new, ';') == 1)
            execute_multi(new, env, bash);
        else
            execute(bash, new, env);
    }
    free_allocation(bash, new, user);
    return 0;
}

char *new_env(char **env)
{
    char *new_env = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            new_env = env[i];
            break;
        }
    }
    return new_env;
}

char *name(char **env)
{
    int i = 0;
    char *dest = NULL;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], "USER=", 5) == 0) {
            dest = copy(env[i], 5);
            break;
        }
        i += 1;
    }
    return dest;
}

char *copy(char *str, int n)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) - n + 1));
    int i = 0;
    int j = 0;

    for (i = n; str[i] != '\0'; i++) {
        dest[j] = str[i];
        j += 1;
    }
    dest[j] = '\0';
    return dest;
}
