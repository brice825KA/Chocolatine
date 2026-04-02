/*
** EPITECH PROJECT, 2026
** signal of segfault
** File description:
** signal of segfault
*/

#include "../include/my.h"

void segfault(pid_t pid)
{
    int status;

    waitpid(pid, &status, 0);
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV)
            write(2, "Segmentation fault", 18);
        if (WTERMSIG(status) == SIGFPE)
            write(2, "Floating exception", 18);
        if (WCOREDUMP(status))
            write(2, " (core dumped)", 14);
        write(2, "\n", 1);
    }
}
