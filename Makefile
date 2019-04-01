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
		srcs/weights.c\
		srcs/affichage.c\
		srcs/algo.c\
		srcs/choose_path.c\
		srcs/ft_check_precedents.c\
		srcs/graph_utils.c\
		srcs/frees_algo.c\
		srcs/utils_algo.c\
		srcs/check_commandes.c\
		srcs/check_file.c\
		srcs/get_file.c\
		srcs/init_data.c\
		srcs/init_struct.c\
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
		srcs/choose_path.c\
		srcs/graph_utils.c\
		srcs/ft_check_precedents.c\
		srcs/frees_algo.c\
		srcs/utils_algo.c\
		srcs/check_commandes.c\
		srcs/check_file.c\
		srcs/get_file.c\
		srcs/init_data.c\
		srcs/init_struct.c\
		srcs/liberation.c\
		srcs/list_chain.c\
		srcs/logical_infos_box.c\
		srcs/parsing.c\
		srcs/valeur_data.c\
		srcs/valeur_pipe.c\
		srcs/resolution.c\
		srcs/move_ants.c\
		srcs/list_utils.c\
		srcs/weights.c

LIB = libft/libft.a

OBJET = $(SRC:.c=.o)

OBJET_BONUS = $(SRC_BONUS:.c=.o)

INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror -O1 -I $(INCLUDES) -g3 #-fsanitize=address

CC = clang

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

$(OBJET) : includes/lem_in.h
$(OBJET_BONUS) : includes/visu.h

$(NAME) : $(LIB) $(OBJET)
	@$(CC) $(CFLAGS) $(LIB) $(OBJET) -o $@

$(NAME_BONUS) : $(LIB) $(OBJET_BONUS)
	@ $(CC) $(CFLAGS) $(LIB) $(OBJET_BONUS) -lmlx -framework OpenGL -framework AppKit -o $@
	@# $(CC) $(CFLAGS) $(LIB) $(OBJET_BONUS)  /usr/X11/lib/libmlx.a -framework OpenGL -framework AppKit -o $@

exe_one : $(NAME)
	./lem-in < resources/correct/2.map

exe : $(NAME)
	sh script.sh $(arg) $(arg_2)

cat :
	cat resources/sortie_error_lem-in_correct | grep "definitely lost:" | more
	cat resources/sortie_error_lem-in_correct | grep "indirectly lost:" | more
	cat resources/sortie_error_lem-in_correct | grep "possibly lost:" | more

	cat resources/sortie_error_lem-in_error | grep "ERROR" | more
	cat resources/sortie_error_lem-in_error | grep "definitely lost:" | more
	cat resources/sortie_error_lem-in_error | grep "indirectly lost:" | more
	cat resources/sortie_error_lem-in_error | grep "possibly lost:" | more
	
	cat resources/sortie_error_visu_error | grep "Wrong Data " | more
	cat resources/sortie_error_visu_error | grep "definitely lost:" | more
	cat resources/sortie_error_visu_error | grep "indirectly lost:" | more
	cat resources/sortie_error_visu_error | grep "possibly lost:" | more

map :
	./resources/map_edit $(arg) $(arg_2) resources/$(arg_3)

clean :
	@rm -f $(OBJET) $(OBJET_BONUS)
	@make clean -C libft

fclean : clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C libft

re : fclean all
