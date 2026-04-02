/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <unistd.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <string.h>
    #include <signal.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <dirent.h>
    #include <sys/stat.h>

typedef struct minishell {
    int id;
    char *pathname;
    struct minishell *next;
} shell_t;

void execute_multi(char *sent, char **env, shell_t *bash);
char **multi_arg(char *str);
void segfault(pid_t pid);
char *error_arg(char *com, char **new_arg);
static void gest_setenv(char **env, char **new_arg);
char *name(char **env);
char *copy(char *str, int n);
char **built_in_setenv(char **env, char **args);
void free_env(char **new_env);
void print_env(char **env);
char **copy_env(char **env);
char *value_rec(char *dest, char *value, int len);
int error_cd(char *dest);
void cd_bultin(char **args, char **env);
char *get_env_value(char **env, char *key);
char *new_env(char **env);
char *loop_function(shell_t *path, char **new_arg, char *res);
void pid_function(char *str, char **env, char **arg);
int my_strchr(char *str, char c);
char *exect(char *str);
void execut_fork(char *str, char **env, char **arg);
char *search_command(char *path, char *command);
void execute(shell_t *bash, char *com, char **env);
shell_t *new_str_to_word(char *str_or);
char **my_str_to_word_array(char *str);
char *my_concat_params(char *s1, char *s2);
int func_exit(char *str);
int count(char *str);
int count_word(char *str);
char *first_word(char *str);
int my_sign(char const *dest);
void my_flags(int i, va_list dark, const char *form);
void farg(char c);
void forg(int d);
void furg(char *s);
int my_hexax_nbr(int nb);
int my_hexa_nbr(int nb);
int my_octal_nbr(int nb);
int my_printf(const char *format, ...);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);

#endif
