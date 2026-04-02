/*
** EPITECH PROJECT, 2026
** cd command
** File description:
** cd command
*/

#include "../include/my.h"
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

void cd_bultin(char **args, char **env)
{
    char *dest = NULL;
    char pwd[1024];

    getcwd(pwd, sizeof(pwd));
    if ((args[1] == NULL || my_strcmp(args[1], "~") == 0)) {
        dest = get_env_value(env, "HOME=");
        if (!dest) {
            my_printf("cd: No home directory.\n");
            return;
        } else
            chdir(dest);
    } else if (my_strcmp(args[1], "-") == 0) {
        dest = get_env_value(env, "OLDPWD=");
        chdir(dest);
    } else
        dest = args[1];
    if (dest != NULL && error_cd(dest) == 0)
        chdir(dest);
}

char *get_env_value(char **env, char *key)
{
    int len = my_strlen(key);
    int i = 0;
    char *value = NULL;
    char *path = NULL;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], key, len) == 0) {
            path = malloc(sizeof(char) * (my_strlen(env[i]) - len + 1));
            path = value_rec(path, env[i], len);
            break;
        }
        i++;
    }
    return path;
}

int error_cd(char *dest)
{
    struct stat sb;

    if (stat(dest, &sb) == -1) {
        my_printf("%s: No such file or directory.\n", dest);
        return 1;
    } else if (!S_ISDIR(sb.st_mode)) {
        my_printf("%s: Not a directory.\n", dest);
        return 1;
    }
    return 0;
}

char *value_rec(char *dest, char *value, int len)
{
    int j = 0;
    int i = 0;

    for (j = len; value[j] != '\0'; j++) {
        dest[i] = value[j];
        i++;
    }
    dest[j] = '\0';
    return dest;
}
