/*
** EPITECH PROJECT, 2025
** unit_test
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, flag_d, .init = redirect_all_std)
{
    my_printf("%d", 15);
    cr_assert_stdout_eq_str("15");
}

Test(my_printf, flag_c, .init = redirect_all_std)
{
    my_printf("%c", 'd');
    cr_assert_stdout_eq_str("d");
}

Test(my_printf, flag_s, .init = redirect_all_std)
{
    my_printf("%s", "julsinia est gentille");
    cr_assert_stdout_eq_str("julsinia est gentille");
}

Test(my_printf, flag_o, .init = redirect_all_std)
{
    my_printf("%o", 67);
    cr_assert_stdout_eq_str("103");
}

Test(my_printf, mix_1, .init = redirect_all_std)
{
    my_printf("%d et %c", 100, 'c');
    cr_assert_stdout_eq_str("100 et c");
}

Test(my_printf, mix_2, .init = redirect_all_std)
{
    my_printf("%s %d %s", "hello i have", 15, "years old");
    cr_assert_stdout_eq_str("hello i have 15 years old");
}

Test(my_printf, only_sente, .init = redirect_all_std)
{
    my_printf("%s", "best friend");
    cr_assert_stdout_eq_str("best friend");
}

Test(my_octal_nbr, one_test, .init = redirect_all_std)
{
    my_octal_nbr(67);
    cr_assert_stdout_eq_str("103");
}

Test(my_printf, negatif_number, .init = redirect_all_std)
{
    my_printf("%d", -15);
    cr_assert_stdout_eq_str("-15");
}
