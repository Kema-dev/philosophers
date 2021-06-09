# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 10:55:11 by jjourdan          #+#    #+#              #
#    Updated: 2021/04/21 17:27:40 by jjourdan         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# *******************************    POST-IT    ****************************** #
#                                                                              #
#			## $@ 	Le nom de la cible										   #
#			## $< 	Le nom de la première dépendance						   #
#			## $^ 	La liste des dépendances								   #
#			## $? 	La liste des dépendances plus récentes que la cible		   #
#			## $* 	Le nom du fichier sans suffixe							   #
#                                                                              #
# **************************************************************************** #

NAME		=	my_project

ARGS		=	foo bar

CC			=	gcc

RM			=	rm -f

FLAGS		=	-Wall -Wextra -Werror

DEBUG_FLAGS	=	-Wall -Wextra -fsanitize=address

DEBUG_OUT	=	debug.out

INCS_DIR	=	includes/

INCS		=	my_project.h

INCS_FULL	=	$(addprefix $(INCS_DIR), $(INCS))

SRCS_DIR	=	sources/

SRCS		=	main.c

SRCS_FULL	=	$(addprefix $(SRCS_DIR), $(SRCS))

OBJS		=	$(SRCS_FULL:.c=.o)

MAKE_SUB	=	make -C

LIBS_DIR	=	libs/

LIBS		=	libkema/

LIBS_FULL	=	$(addprefix $(LIBS_DIR), $(LIBS))

LIBS_FILES	=	libs/libkema/libkema.a

all:			libraries $(NAME)

%.o: 			%.c $(INCS_FULL)
				$(CC) $(FLAGS) -I $(INCS_DIR) -c $< -o $@

$(NAME): 		$(OBJS)
				$(CC) -I $(INCS_DIR) $(OBJS) $(LIBS_FILES) -o $(NAME)

libraries:
				$(foreach lib,$(LIBS_FULL), $(MAKE_SUB) $(lib))

norme:			fclean
				printf "\033c"
				$(foreach lib,$(LIBS_FULL), norminette $(lib))
				norminette $(SRCS_DIR)
				norminette $(INCS_DIR)

norme_check:	fclean
				printf "\033c"
				$(foreach lib,$(LIBS_FULL), norminette $(lib)) | grep " KO!" | wc -l
				norminette $(SRCS_DIR) | grep " KO!" | wc -l
				norminette $(INCS_DIR) | grep " KO!" | wc -l

debug:			libraries $(OBJS)
				$(CC) -I $(INCS_DIR) $(DEBUG_FLAGS) $(OBJS) $(LIBS_FILES) -o $(DEBUG_OUT)
				printf "\033c"
				./$(DEBUG_OUT) $(ARGS)

valgrind:		all
				printf "\ec"
				valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS) 

leaks:			all
				printf "\033c"
				leaks --atExit -- ./$(NAME) $(ARGS)

clean:
				$(RM) $(OBJS)
				$(foreach lib_dir,$(LIBS_FULL), $(MAKE_SUB) $(lib_dir) clean)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(DEBUG_OUT)
				$(foreach lib_dir,$(LIBS_FULL), $(MAKE_SUB) $(lib_dir) fclean)

re:				fclean all

.PHONY: all, libs, norme, norme_check, debug, valgrind, leaks, clean, fclean, re