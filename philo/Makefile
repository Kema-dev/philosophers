# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 10:55:11 by jjourdan          #+#    #+#              #
#    Updated: 2021/06/12 17:01:00 by jjourdan         ###   ########lyon.fr    #
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

NAME		=	philo

ARGS		=	4 310 200 100
#	*	nb philo / time to die / time to eat / time to sleep - nb times must eat

CC			=	gcc

RM			=	rm -f

FLAGS		=	-Wall -Wextra -Werror

DEBUG_FLAGS	=	-Wall -Wextra -fsanitize=address

DEBUG_OUT	=	debug.out

INCS_DIR	=	includes/

INCS		=	philosophers.h

INCS_FULL	=	$(addprefix $(INCS_DIR), $(INCS))

SRCS_DIR	=	sources/

SRCS		=	main.c \
				philo_1.c \
				philo_fight.c \
				philo_utils.c \
				kemalloc.c \
				philo_libft.c

SRCS_FULL	=	$(addprefix $(SRCS_DIR), $(SRCS))

OBJS		=	$(SRCS_FULL:.c=.o)

MAKE_SUB	=	make -C

all:			$(NAME)

%.o: 			%.c $(INCS_FULL)
				$(CC) $(FLAGS) -I $(INCS_DIR) -c $< -o $@

$(NAME): 		$(OBJS)
				$(CC) $(FLAGS) -I $(INCS_DIR) $(OBJS) -o $(NAME)

norme:			fclean
				printf "\ec"
				norminette $(SRCS_DIR)
				norminette $(INCS_DIR)

norme_check:	fclean
				printf "\ec"
				norminette $(SRCS_DIR) | grep " KO!" | wc -l
				norminette $(INCS_DIR) | grep " KO!" | wc -l

debug:			all
				$(CC) -I $(INCS_DIR) $(DEBUG_FLAGS) $(OBJS) -o $(DEBUG_OUT)
				printf "\ec"
				./$(DEBUG_OUT) $(ARGS)

valgrind:		all
				printf "\ec"
				valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS) 

leaks:			all
				printf "\033c"
				leaks --atExit -- ./$(NAME) $(ARGS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(DEBUG_OUT)

re:				fclean all

.PHONY: all, norme, norme_check, debug, valgrind, leaks, clean, fclean, re