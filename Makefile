##
## Makefile for makefile in /home/odet_a/rendu/Bistro
## 
## Made by 
## Login   <odet_a@epitech.net>
## 
## Started on  Mon Nov  4 16:31:01 2013 
## Last update Fri Nov  8 14:29:56 2013 
##

SRC=		eval_expr.c \
		main.c \
		my_error.c \
		Evaluation/infinite_add.c \
		Evaluation/infinite_div.c \
		Evaluation/infinite_doop.c \
		Evaluation/infinite_mod.c \
		Evaluation/infinite_mul.c \
		Evaluation/infinite_sub.c \
		Evaluation/my_op_fun.c \
		Evaluation/my_strndup.c \
		Lexing/my_neg_special.c \
		Lexing/my_npi.c \
		Lexing/my_str_to_chain.c \
		Lexing/parenthese.c

LIB_S=		my/my_getnbr.c \
		my/my_putchar.c \
		my/my_putstr.c \
		my/my_revstr.c \
		my/my_strcmp.c \
		my/my_strcpy.c \
		my/my_strlen.c \
		my/my_strncmp.c \
		my/my_strncpy.c \
		my/my_swap.c \
		my/my_strdup.c \
		my/xmalloc.c \
		my/my_list_size.c

CC=		gcc -W -Wall -Werror

NAME=		calc

LIB_N=		libmy.a

OBJ=		$(SRC:.c=.o)

LIB_O=		$(LIB_S:.c=.o)

all:		$(LIB_N) $(NAME)

$(LIB_N):	$(LIB_O)
		ar rc $(LIB_N) $(LIB_O)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lmy -L.

clean:
		rm -f $(OBJ)
		rm -f $(LIB_O)

fclean:		clean
		rm -f $(NAME)
		rm -f $(LIB_N)

re:		fclean all
