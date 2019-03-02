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

NAME_BONUS = visu

SRC =	srcs/main.c\
		srcs/affichage.c\
		srcs/algo.c\
		srcs/choose_path.c\
		srcs/ft_search_path.c\
		srcs/graph_utils.c\
		srcs/frees_algo.c\
		srcs/utils_algo.c\
		srcs/check_commandes.c\
		srcs/check_file.c\
		srcs/get_file.c\
		srcs/init_data.c\
		srcs/liberation.c\
		srcs/list_chain.c\
		srcs/logical_infos_box.c\
		srcs/parsing.c\
		srcs/valeur_data.c\
		srcs/valeur_pipe.c\
		srcs/resolution.c\
		srcs/move_ants.c\
		srcs/list_utils.c

SRC_BONUS = srcs_bonus/main_bonus.c\
		srcs/affichage.c\
		srcs/algo.c\
		srcs/choose_path.c\
		srcs/graph_utils.c\
		srcs/ft_search_path.c\
		srcs/frees_algo.c\
		srcs/utils_algo.c\
		srcs/check_commandes.c\
		srcs/check_file.c\
		srcs/get_file.c\
		srcs/init_data.c\
		srcs/liberation.c\
		srcs/list_chain.c\
		srcs/logical_infos_box.c\
		srcs/parsing.c\
		srcs/valeur_data.c\
		srcs/valeur_pipe.c\
		srcs/resolution.c\
		srcs/move_ants.c\
		srcs/list_utils.c

LIB = libft/libft.a

OBJET = $(SRC:.c=.o)

OBJET_BONUS = $(SRC_BONUS:.c=.o)

INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES) #-fsanitize=address

CC = clang

leak= valgrind --leak-check=full

arg = 0
arg_2 = 0
arg_3 = 0

all : $(NAME) $(NAME_BONUS)

$(OBJET): includes/lem-in.h

$(NAME) : $(OBJET)
	@make -C libft
	@$(CC) $(CFLAGS) $(LIB) $(OBJET) -o $@

$(NAME_BONUS) : $(OBJET_BONUS)
	@make -C libft
	@$(CC) $(CFLAGS) $(LIB) $(OBJET_BONUS) -lmlx -framework OpenGL -framework AppKit -o $@


exe_one : $(NAME)
	valgrind --leak-check=full --show-leak-kinds=definite ./lem-in < resources/error_22
	@read $VAR
	./visu < resources/error_22
	@read $VAR
	./lem-in < resources/error_22 | ./visu
	@read $VAR
	# ./lem-in < resources/error_22 | valgrind --leak-check=full --show-leak-kinds=definite ./visu
	# @read $VAR
	

	valgrind --leak-check=full --show-leak-kinds=definite ./lem-in < resources/correct_11
	@read $VAR
	./visu < resources/correct_11
	@read $VAR
	./lem-in < resources/correct_11 | ./visu
	# @read $VAR
	# ./lem-in < resources/correct_11 | valgrind --leak-check=full --show-leak-kinds=definite ./visu


exe : $(NAME)
ifeq ($(arg), correct)
	./lem-in < resources/correct_1 | ./visu
	./lem-in < resources/correct_2 | ./visu
	./lem-in < resources/correct_3 | ./visu
	./lem-in < resources/correct_4 | ./visu
	./lem-in < resources/correct_5 | ./visu
	./lem-in < resources/correct_6 | ./visu
	./lem-in < resources/correct_7 | ./visu
	./lem-in < resources/correct_8 | ./visu
	./lem-in < resources/correct_9 | ./visu
	./lem-in < resources/correct_10 | ./visu
	./lem-in < resources/correct_11 | ./visu
	./lem-in < resources/correct_gen_1 | ./visu
	./lem-in < resources/correct_gen_2 | ./visu
	./lem-in < resources/map_git | ./visu
	./lem-in < resources/map_git1 | ./visu
	./lem-in < resources/map_git3 | ./visu
	./lem-in < resources/map_offi | ./visu
	./lem-in < resources/map_offi_custom | ./visu
	./lem-in < resources/map_offi_no_way | ./visu
	./lem-in < resources/map_offi_pipe_error | ./visu
	./lem-in < resources/maptest | ./visu
	./lem-in < resources/norooms | ./visu
else
	./lem-in < srcs
	./lem-in < lem-in
	./lem-in < auteur
	@read $VAR
	./lem-in < resources/error_1 | ./visu
	./lem-in < resources/error_2 | ./visu
	./lem-in < resources/error_3 | ./visu
	./lem-in < resources/error_4 | ./visu
	./lem-in < resources/error_5 | ./visu
	@read $VAR
	./lem-in < resources/error_6 | ./visu
	./lem-in < resources/error_7 | ./visu
	./lem-in < resources/error_8 | ./visu
	./lem-in < resources/error_9 | ./visu
	./lem-in < resources/error_10 | ./visu
	@read $VAR
	./lem-in < resources/error_11 | ./visu
	./lem-in < resources/error_12 | ./visu
	./lem-in < resources/error_13 | ./visu
	./lem-in < resources/error_14 | ./visu
	./lem-in < resources/error_15 | ./visu
	@read $VAR
	./lem-in < resources/error_16 | ./visu
	./lem-in < resources/error_17 | ./visu
	./lem-in < resources/error_18 | ./visu
	./lem-in < resources/error_19 | ./visu
	@read $VAR
	./lem-in < resources/error_20 | ./visu
	./lem-in < resources/error_21 | ./visu
	./lem-in < resources/error_22 | ./visu
	./lem-in < resources/error_23 | ./visu
	@read $VAR
	./lem-in < resources/error_24 | ./visu
	./lem-in < resources/error_25 | ./visu
	./lem-in < resources/error_26 | ./visu
	./lem-in < resources/error_27 | ./visu
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
	@rm -f $(OBJET) $(OBJET_BONUS)
	@make clean -C libft

fclean : clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C libft

re : fclean all
