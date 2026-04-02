/*
** EPITECH PROJECT, 2025
** mini_printf
** File description:
** mini_printf
*/

#include "../include/my.h"

void my_flags(int i, va_list dark, const char *form)
{
    if (form[i] == '%' && form[i + 1] == 'c')
        farg(va_arg(dark, int));
    if (form[i] == '%' && form[i + 1] == 'o')
        my_octal_nbr(va_arg(dark, int));
    if (form[i] == '%' && form[i + 1] == 'd')
        forg(va_arg(dark, int));
    if (form[i] == '%' && form[i + 1] == 'i')
        forg(va_arg(dark, int));
    if (form[i] == '%' && form[i + 1] == 's')
        furg(va_arg(dark, char *));
    if (form[i] == '%' && form[i + 1] == '%')
        my_putchar('%');
}

void farg(char c)
{
    my_putchar(c);
}

void forg(int d)
{
    my_put_nbr(d);
}

void furg(char *s)
{
    my_putstr(s);
}

int my_printf(const char *form, ...)
{
    int i;
    va_list dark;

    va_start(dark, form);
    i = 0;
    while (form[i] != '\0') {
        if (form[i] == '%') {
            my_flags(i, dark, form);
            i += 1;
        } else
            my_putchar(form[i]);
        i++;
    }
    va_end(dark);
    return 0;
}
