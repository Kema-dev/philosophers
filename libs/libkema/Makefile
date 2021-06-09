# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 11:26:11 by jjourdan          #+#    #+#              #
#    Updated: 2021/04/22 13:59:36 by jjourdan         ###   ########lyon.fr    #
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

FLAGS		=	-Wall -Wextra -Werror

NAME		=	libkema.a

CC			=	gcc

RM			=	rm -f

INC_DIR	=	includes/

INCLUDES	=	libft.h \
				gnl.h \
				ft_dprintf.h \
				libkema.h

INC_FULL	=	$(addprefix $(INC_DIR), $(INCLUDES))

SRCS_DIR	=	sources/

LIBFT_DIR	=	libft/

LIBFT_SRCS	=	ft_putchar.c \
				ft_strlen.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_bzero.c \
				ft_memset.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strncmp.c \
				ft_strlcpy.c \
				ft_atoi.c \
				ft_strdup.c \
				ft_strlcat.c \
				ft_strrchr.c \
				ft_strchr.c \
				ft_strnstr.c \
				ft_calloc.c \
				ft_strcat.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_strmapi.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstprint.c \
				kemalloc.c

LIBFT_FULL	=	$(addprefix $(LIBFT_DIR), $(LIBFT_SRCS))

GNL_DIR		=	gnl/

GNL_SRCS	=	ft_gnl_1.c \
				ft_gnl_2.c

GNL_FULL	=	$(addprefix $(GNL_DIR), $(GNL_SRCS))

DPRINTF_DIR	=	ft_dprintf/

DPRINTF_SRCS	=	sources/utils/ft_dprintf_atoi.c \
				sources/utils/ft_dprintf_itoa.c \
				sources/utils/ft_dprintf_memset.c \
				sources/utils/ft_dprintf_putchar_fd.c \
				sources/utils/ft_dprintf_strlen.c \
				sources/utils/ft_dprintf_utoa.c \
				sources/utils/ft_dprintf_xtoa.c \
				sources/utils/ft_dprintf_putstr_fd.c \
				sources/utils/ft_dprintf_ptoa.c \
				sources/ft_dprintf_flag_init.c \
				sources/ft_dprintf_flag_reset.c \
				sources/ft_dprintf_get_add_flags.c \
				sources/ft_dprintf_get_first_flags.c \
				sources/ft_dprintf_get_flag.c \
				sources/ft_dprintf_get_prec.c \
				sources/ft_dprintf_get_type.c \
				sources/ft_dprintf_get_width.c \
				sources/ft_dprintf_print_c.c \
				sources/ft_dprintf_print_s.c \
				sources/ft_dprintf_print_x.c \
				sources/ft_dprintf.c \
				sources/ft_dprintf_treat_flag.c \
				sources/ft_dprintf_treat_input.c \
				sources/ft_dprintf_print_normal.c \
				sources/ft_dprintf_print_percent.c \
				sources/ft_dprintf_print_p.c

DPRINTF_FULL	=	$(addprefix $(DPRINTF_DIR), $(DPRINTF_SRCS))

ALL_SRCS	+=	$(LIBFT_FULL)
ALL_SRCS	+=	$(GNL_FULL)
ALL_SRCS	+=	$(DPRINTF_FULL)

SRCS_FULL	=	$(addprefix $(SRCS_DIR), $(ALL_SRCS))

DEBUG_FULL	+=	$(SRCS_FULL)
DEBUG_FULL	+=	main.c

OBJS		=	$(SRCS_FULL:.c=.o)

DEBUG_OBJS	=	$(DEBUG_FULL:.c=.o)

all:			$(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $?

%.o: %.c		$(INC_FULL)
		$(CC) -I $(INC_DIR) $(FLAGS) -c $< -o $@

debug:			all $(DEBUG_OBJS)
		$(CC) -Wall -Wextra -I $(INC_DIR) $(NAME) $(DEBUG_OBJS) -o debug.out

clean:
		$(RM) $(OBJS)

fclean:			clean
		$(RM) $(NAME)

re:				fclean all

.PHONY: all, clean, fclean, re
