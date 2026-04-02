#/
## EPITECH PROJECT, 2025
## my_octal_nbr
## File description:
## my_octal_nbr
#/

src	=	./file/my_printf.c	\
		./file/my_putnbr.c	\
		./file/my_putchar.c	\
		./file/my_revstr.c	\
		./file/my_putstr.c	\
		./file/my_octal_nbr.c	\
		./file/my_getnbr.c	\
		./file/my_hexa_nbr.c	\
		./file/my_hexax_nbr.c	\
		./file/my_sign.c	\
		./file/my_putstr.c	\
		./file/my_strcmp.c	\
		./file/my_strcpy.c	\
		./file/my_strdup.c	\
		./test/base_tests.c	\

obj   =		$(src:.c=.o)

name  =		libmy.a

cc    =		clang

CFLAGS =	-g -w -Wall -Wextra -Werror

all: $(name)

$(name):    $(obj)
	ar rc libmy.a $(obj)

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(name)
	rm -f mouli

auteur:
	echo $(user) > auteur

re:	fclean all

test_run: ./test/base_tests.o ./file/my_printf.o ./file/my_putnbr.o ./file/my_putchar.o ./file/my_octal_nbr.o ./file/my_putchar.o ./file/my_putstr.o ./file/my_hexa_nbr.o
	$(cc) $(CFLAGS) -o mouli ./test/base_tests.o ./file/my_printf.o ./file/my_putnbr.o  ./file/my_octal_nbr.o  ./file/my_putchar.o ./file/my_putstr.o ./file/my_hexa_nbr.o -lcriterion --coverage
	./mouli
