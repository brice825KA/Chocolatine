#/
## EPITECH PROJECT, 2025
## my_octal_nbr
## File description:
## my_octal_nbr
#/

src	=	$(wildcard ./file/*.c)

file_test	=	$(wildcard ./file-test/file/*.c)

obj   =		$(src:.c=.o)

name  =		mysh

cc    =		clang

CFLAGS =	-g -w -Wall -Wextra -Werror -g3

TESTNAME	=	unit_tests

COV	=	-coverage -lcriterion -lgcov

all: $(name)

$(name):    $(obj)
	        $(cc) $(CFLAGS) -o $(name) $(obj)

clean:
	        rm -f $(obj)

fclean: clean
	        rm -f $(name)
	        rm -f $(TESTNAME)
			rm -f *.gcda *.gcno

auteur:
	        echo $(user) > auteur

re:	fclean all

unit_tests:
	    $(cc) $(file_test) $(CFLAGS) $(COV) -o $(TESTNAME) $(COV)

tests_run: $(TESTNAME)
	      ./$(TESTNAME)
