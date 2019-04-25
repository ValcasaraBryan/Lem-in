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

NAME_VERIF = verif/check_result

SRC =	srcs/main.c\
		srcs/affichage.c\
		srcs/algo.c\
		srcs/check_commandes.c\
		srcs/check_file.c\
		srcs/edmonds.c\
		srcs/find_paths.c\
		srcs/frees_algo.c\
		srcs/ft_check_precedents.c\
		srcs/ft_update_tab_path.c\
		srcs/get_file.c\
		srcs/graph_utils.c\
		srcs/init_data.c\
		srcs/init_struct.c\
		srcs/liberation.c\
		srcs/list_chain.c\
		srcs/logical_infos_box.c\
		srcs/move_ants.c\
		srcs/parsing.c\
		srcs/resolution.c\
		srcs/save_groups_paths.c\
		srcs/utils.c\
		srcs/utils_edmonds.c\
		srcs/utils_list.c\
		srcs/utils_resolution.c\
		srcs/valeur_data.c\
		srcs/valeur_pipe.c\
		srcs/weights.c

SRC_BONUS = srcs_bonus/main_bonus.c\
			srcs_bonus/liberation_bonus.c\
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
		srcs/check_commandes.c\
		srcs/check_file.c\
		srcs/edmonds.c\
		srcs/find_paths.c\
		srcs/frees_algo.c\
		srcs/ft_check_precedents.c\
		srcs/ft_update_tab_path.c\
		srcs/get_file.c\
		srcs/graph_utils.c\
		srcs/init_data.c\
		srcs/init_struct.c\
		srcs/liberation.c\
		srcs/list_chain.c\
		srcs/logical_infos_box.c\
		srcs/move_ants.c\
		srcs/parsing.c\
		srcs/resolution.c\
		srcs/save_groups_paths.c\
		srcs/utils.c\
		srcs/utils_edmonds.c\
		srcs/utils_list.c\
		srcs/utils_resolution.c\
		srcs/valeur_data.c\
		srcs/valeur_pipe.c\
		srcs/weights.c

SRC_VERIF = verif/verif.c

LIB = libft/libft.a

OBJET = $(SRC:.c=.o)

OBJET_BONUS = $(SRC_BONUS:.c=.o)

OBJET_VERIF = $(SRC_VERIF:.c=.o)

INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)# -fsanitize=address

CC = gcc

leak = valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all# --show-leak-kinds=definite

arg = 0
arg_2 = 0
arg_3 = 0

lem-in_correct = resources/sortie_error_lem_in_correct
visu_correct = resources/sortie_error_visu_correct
lem-in_error = resources/sortie_error_lem_in_error
visu_error = resources/sortie_error_visu_error

opti :
	@make -j8 all

all :
	@make -C libft
	@make $(NAME)
	@make $(NAME_BONUS)
	@make $(NAME_VERIF)

$(OBJET) : includes/lem_in.h
$(OBJET_BONUS) : includes/visu.h

$(NAME) : $(LIB) $(OBJET) Makefile
	@$(CC) $(CFLAGS) $(LIB) $(OBJET) -o $@

$(NAME_BONUS) : $(LIB) $(OBJET_BONUS) Makefile
	@$(CC) $(CFLAGS) $(LIB) $(OBJET_BONUS) -lmlx -framework OpenGL -framework AppKit -o $@
	@# $(CC) $(CFLAGS) $(LIB) $(OBJET_BONUS)  /usr/X11/lib/libmlx.a -framework OpenGL -framework AppKit -o $@

$(NAME_VERIF) : $(LIB) $(OBJET_VERIF) Makefile
	@$(CC) $(CFLAGS) $(LIB) $(OBJET_VERIF) -o $@

exe_one : all $(NAME)
	@time ./lem-in < $(arg)

exe : all $(NAME)
	@sh script.sh $(arg) $(arg_2)
	#time ./lem-in < big_superposition_14 > coucou && make check arg=coucou
	#time ./lem-in < big_superposition_18 > coucou && make check arg=coucou
	#time ./lem-in < big_superposition_20 > coucou && make check arg=coucou
	#time ./lem-in < big_superposition_37 > coucou && make check arg=coucou
	#time ./lem-in < big_superposition_39 > coucou && make check arg=coucou
	#time ./lem-in < big_superposition_43 > coucou && make check arg=coucou
	#time ./lem-in < big_superposition_49 > coucou && make check arg=coucou

check : $(NAME_VERIF)
	@./$(NAME_VERIF) $(arg) >> $(arg_2)

cat :
	cat resources/sortie_error_lem_in_correct | grep "definitely lost:" | more
	cat resources/sortie_error_lem_in_correct | grep "indirectly lost:" | more
	cat resources/sortie_error_lem_in_correct | grep "possibly lost:" | more

	cat resources/sortie_error_lem_in_error | grep "ERROR" | more
	cat resources/sortie_error_lem_in_error | grep "definitely lost:" | more
	cat resources/sortie_error_lem_in_error | grep "indirectly lost:" | more
	cat resources/sortie_error_lem_in_error | grep "possibly lost:" | more
	
	cat resources/sortie_error_visu_error | grep "Wrong Data " | more
	cat resources/sortie_error_visu_error | grep "definitely lost:" | more
	cat resources/sortie_error_visu_error | grep "indirectly lost:" | more
	cat resources/sortie_error_visu_error | grep "possibly lost:" | more

map :
	./resources/map_edit $(arg) $(arg_2) resources/$(arg_3)

clean :
	@rm -f $(OBJET) $(OBJET_BONUS) $(OBJET_VERIF)
	@make clean -C libft

fclean : clean
	@rm -f $(NAME) $(NAME_BONUS) $(NAME_VERIF)
	@make fclean -C libft

re : fclean all
