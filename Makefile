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
		srcs/affichage.c\
		srcs/algo.c\
		srcs/choose_path.c\
		srcs/check_commandes.c\
		srcs/check_file.c\
		srcs/get_file.c\
		srcs/init_data.c\
		srcs/liberation.c\
		srcs/list_chain.c\
		srcs/logical_infos_box.c\
		srcs/parsing.c\
		srcs/valeur_data.c\
		srcs/valeur_pipe.c

LIB = libft/libft.a

OBJET = $(SRC:.c=.o)

INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

CC = gcc

leak= valgrind --leak-check=full

arg = 0
arg_2 = 0
arg_3 = 0

all : $(NAME)

$(OBJET): includes/lem-in.h

$(NAME) : $(OBJET)
	@make -C libft
	@$(CC) $(CFLAGS) $(LIB) $(OBJET) -o $@

exe : $(NAME)
ifeq ($(arg), correct)
	./lem-in < resources/correct_1
	@read $VAR
	./lem-in < resources/correct_2
	@read $VAR
	./lem-in < resources/correct_3
	@read $VAR
	./lem-in < resources/correct_4
	@read $VAR
	./lem-in < resources/correct_5
else
	./lem-in < srcs
	./lem-in < lem-in
	./lem-in < auteur
	@read $VAR
	./lem-in < resources/error_1
	./lem-in < resources/error_2
	./lem-in < resources/error_3
	./lem-in < resources/error_4
	./lem-in < resources/error_5
	@read $VAR
	./lem-in < resources/error_6
	./lem-in < resources/error_7
	./lem-in < resources/error_8
	./lem-in < resources/error_9
	./lem-in < resources/error_10
	@read $VAR
	./lem-in < resources/error_11
	./lem-in < resources/error_12
	./lem-in < resources/error_13
	./lem-in < resources/error_14
	./lem-in < resources/error_15
	@read $VAR
	./lem-in < resources/error_16
	./lem-in < resources/error_17
	./lem-in < resources/error_18
	./lem-in < resources/error_19
	@read $VAR
	./lem-in < resources/error_20
	./lem-in < resources/error_21
	./lem-in < resources/error_22
	./lem-in < resources/error_23
	@read $VAR
	./lem-in < resources/error_24
	./lem-in < resources/error_25
	./lem-in < resources/error_26
	./lem-in < resources/error_27
endif

exe_leak : $(NAME)
ifeq ($(arg), correct)
	$(leak) ./lem-in < resources/correct_1
	@read $VAR
	$(leak) ./lem-in < resources/correct_2
	@read $VAR
	$(leak) ./lem-in < resources/correct_3
	@read $VAR
	$(leak) ./lem-in < resources/correct_4
	@read $VAR
	$(leak) ./lem-in < resources/correct_5
else
	$(leak) ./lem-in < srcs
	@read $VAR
	$(leak) ./lem-in < lem-in
	@read $VAR
	$(leak) ./lem-in < auteur
	@read $VAR
	$(leak) ./lem-in < resources/error_1
	@read $VAR
	$(leak) ./lem-in < resources/error_2
	@read $VAR
	$(leak) ./lem-in < resources/error_3
	@read $VAR
	$(leak) ./lem-in < resources/error_4
	@read $VAR
	$(leak) ./lem-in < resources/error_5
	@read $VAR
	$(leak) ./lem-in < resources/error_6
	@read $VAR
	$(leak) ./lem-in < resources/error_7
	@read $VAR
	$(leak) ./lem-in < resources/error_8
	@read $VAR
	$(leak) ./lem-in < resources/error_9
	@read $VAR
	$(leak) ./lem-in < resources/error_10
	@read $VAR
	$(leak) ./lem-in < resources/error_11
	@read $VAR
	$(leak) ./lem-in < resources/error_12
	@read $VAR
	$(leak) ./lem-in < resources/error_13
	@read $VAR
	$(leak) ./lem-in < resources/error_14
	@read $VAR
	$(leak) ./lem-in < resources/error_15
	@read $VAR
	$(leak) ./lem-in < resources/error_16
	@read $VAR
	$(leak) ./lem-in < resources/error_17
	@read $VAR
	$(leak) ./lem-in < resources/error_18
	@read $VAR
	$(leak) ./lem-in < resources/error_19
	@read $VAR
	$(leak) ./lem-in < resources/error_20
	@read $VAR
	$(leak) ./lem-in < resources/error_21
	@read $VAR
	$(leak) ./lem-in < resources/error_22
	@read $VAR
	$(leak) ./lem-in < resources/error_23
	@read $VAR
	$(leak) ./lem-in < resources/error_24
	@read $VAR
	$(leak) ./lem-in < resources/error_25
	@read $VAR
	$(leak) ./lem-in < resources/error_26
	@read $VAR
	$(leak) ./lem-in < resources/error_27
endif
map :
	./resources/map_edit $(arg) $(arg_2) resources/$(arg_3)

clean :
	@rm -f $(OBJET)
	@make clean -C libft

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft

re : fclean all
