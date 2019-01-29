# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 23:28:47 by brvalcas          #+#    #+#              #
#    Updated: 2018/11/30 23:28:47 by brvalcas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC =	srcs/main.c\
		srcs/parsing.c\
		srcs/affichage.c\
		srcs/list_chain.c

LIB = libft/libft.a

OBJET = $(SRC:.c=.o)

INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

CC = gcc

all : $(NAME)

$(OBJET):$(INCLUDES)

$(NAME) : $(OBJET)
	@make -C libft
	@$(CC) $(CFLAGS) $(LIB) $(OBJET) -o $@

exe : $(NAME)
	./lem-in < resources/error_1
	./lem-in < resources/error_2
	./lem-in < resources/error_3
	./lem-in < resources/error_4
	./lem-in < resources/error_5
	./lem-in < resources/error_6
	./lem-in < resources/error_7
	./lem-in < resources/error_8
	./lem-in < resources/error_9
	./lem-in < resources/error_10
	./lem-in < resources/error_11
	./lem-in < resources/error_12
	./lem-in < resources/error_13
	./lem-in < resources/error_14
	./lem-in < resources/error_15
	./lem-in < srcs
	./lem-in < auteur
	./lem-in < resources/correct_1
	./lem-in < resources/correct_2
clean :
	@rm -f $(OBJET)
	@make clean -C libft

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft

re : fclean all
