# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 23:28:47 by brvalcas          #+#    #+#              #
#    Updated: 2019/03/05 15:18:26 by glebouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

NAME_BONUS = visu

SRC =	srcs/main.c\
		srcs/affichage.c\
		srcs/algo.c\
		srcs/choose_path.c\
		srcs/ft_search_path.c\
		srcs/ft_check_precedents.c\
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
			srcs_bonus/parsing_ants_file.c\
			srcs_bonus/init_p.c\
			srcs_bonus/check_file_bonus.c\
			srcs_bonus/get_file_bonus.c\
			srcs_bonus/ants_move.c\
			srcs_bonus/list_graphe.c\
			srcs_bonus/affichage_bonus.c\
			srcs_bonus/grille_win.c\
			srcs_bonus/print_link.c\
			srcs_bonus/draw_line.c\
			srcs_bonus/put_square.c\
			srcs_bonus/utils_bonus.c\
			srcs_bonus/fct_key_hook.c\
		srcs/affichage.c\
		srcs/algo.c\
		srcs/choose_path.c\
		srcs/graph_utils.c\
		srcs/ft_search_path.c\
		srcs/ft_check_precedents.c\
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

leak= valgrind --leak-check=full --track-origins=yes #--show-leak-kinds=all #--show-leak-kinds=definite

arg = 0
arg_2 = 0
arg_3 = 0

all : $(NAME) $(NAME_BONUS)

$(OBJET) : includes/lem-in.h
$(OBJET_BONUS) : includes/visu.h 

$(NAME) : $(OBJET)
	@make -C libft
	@$(CC) $(CFLAGS) $(LIB) $(OBJET) -o $@

$(NAME_BONUS) : $(OBJET_BONUS)
	@make -C libft
	@$(CC) $(CFLAGS) $(LIB) $(OBJET_BONUS) -lmlx -framework OpenGL -framework AppKit -o $@
	@# @$(CC) $(CFLAGS) $(LIB) $(OBJET_BONUS)  /usr/X11/lib/libmlx.a -framework OpenGL -framework AppKit -o $@


exe_one : $(NAME)
	./lem-in < resources/correct_1 | ./visu

	@# For check_memory_leaks use leaks
	@#./visu < coucou
	@	# leaks visu

	@# For debugging use lldb
	@# lldb visu
	@	# settings set target.input-path coucou
	@	# process launch

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
	./lem-in < resources/correctc_10 | ./visu
	./lem-in < resources/correct_11 | ./visu
	./lem-in < resources/map_git | ./visu
	./lem-in < resources/map_git1 | ./visu
	./lem-in < resources/map_git2 | ./visu
	./lem-in < resources/map_git3 | ./visu
	./lem-in < resources/map_offi | ./visu
	./lem-in < resources/map_offi_custom | ./visu
	./lem-in < resources/maptest | ./visu
	./lem-in < resources/g | ./visu
	./lem-in < resources/correct_genc_1 | ./visu
	./lem-in < resources/correct_genc_3 | ./visu
	./lem-in < resources/big | ./visu
	./lem-in < resources/correct_genc_4 | ./visu
	./lem-in < resources/correct_genc_5 | ./visu
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
	@read $VAR
	./lem-in < resources/correct_gen_1 | ./visu
	./lem-in < resources/correct_gen_2 | ./visu
	./lem-in < resources/correct_gen_3 | ./visu
	./lem-in < resources/correct_gen_4 | ./visu
	./lem-in < resources/map_offi_no_way | ./visu
	./lem-in < resources/map_offi_pipe_error | ./visu
	./lem-in < resources/norooms | ./visu
	@read $VAR
	./lem-in < resources/anil | ./visu
	./lem-in < resources/map_correct_gen | ./visu
	./lem-in < resources/correct_genc_2 | ./visu

endif

exe_leak : $(NAME)
ifeq ($(arg), correct)
	$(leak) ./lem-in < resources/correct_1 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/correct_2 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/correct_3 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/correct_4 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/correct_5 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/correct_6 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/correct_7 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/correct_8 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/correct_9 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/correct_10 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/correct_11 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/correct_gen_1 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/correct_gen_2 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/map_git | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/map_git1 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/map_git3 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/map_offi | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/map_offi_custom | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/map_offi_no_way | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/map_offi_pipe_error | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/maptest | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/norooms | ./visu
else
	$(leak) ./lem-in < srcs | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < lem-in | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < auteur | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_1 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_2 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_3 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_4 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_5 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_6 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_7 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_8 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_9 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_10 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_11 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_12 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_13 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_14 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_15 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_16 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_17 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_18 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_19 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_20 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_21 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_22 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_23 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_24 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_25 | ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_26 | $(leak) ./visu
	# @read $VAR
	$(leak) ./lem-in < resources/error_27 | $(leak) ./visu
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
