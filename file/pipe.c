/*
** EPITECH PROJECT, 2026
** pipe main.c
** File description:
** pipe main.c
*/

#include "../include/my.h"

void close_fd(int fd[2])
{
    close(fd[0]);
    close(fd[1]);
}

void wait_proc(pid_t p1, pid_t p2)
{
    waitpid(p1, NULL, 0);
    waitpid(p2, NULL, 0);
}

void execute_cmd(char **one_cmd, char **two_cmd, char **env)
{
    int fd[2];
    pid_t pid;
    pid_t pod;

    if (pipe(fd) < 0)
        return;
    pid = fork();
    if (pid == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close_fd(fd);
        execve(one_cmd[0], one_cmd, env);
    }
    pod = fork();
    if (pod == 0) {
        dup2(fd[0], STDIN_FILENO);
        close_fd(fd);
        execve(two_cmd[0], two_cmd, env);
    }
    close_fd(fd);
    wait_proc(pid, pod);
}

char **parse_cmd(char *str)
{
    char **new_arg = malloc(sizeof(char *) * (count_word(str) + 2));
    char *past = NULL;

    past = strtok(str, " \t\n\0");
    for (int i = 0; i <= count_word(str) + 2 && past; i += 1) {
        new_arg[i] = my_strdup(past);
        past = strtok(NULL, " \t\n");
    }
    new_arg[count_word(str) + 2] = NULL;
    return new_arg;
}
