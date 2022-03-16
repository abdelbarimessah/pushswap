# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amessah <amessah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 20:29:25 by amessah           #+#    #+#              #
#    Updated: 2022/03/16 14:24:08 by amessah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

src = 	checker.c		\
		gnl.c				\
		gnl_utils.c				\
		../ft_mouve.c			\
		../ft_mouve2.c			\
		../ft_mouve3.c			\
		../ft_global_sort.c	\
		../ft_sort_3_5.c		\
		../ft_clear.c			\
		../ft_creat.c			\
		../ft_start_sort.c		\
		../ft_sort_init.c		\
		../ft_return_to_b.c	\
		../ft_utils.c			\

OBJECTS = $(src:.c=.o) 

INCLUDES = 	checker.h	\

		
all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
