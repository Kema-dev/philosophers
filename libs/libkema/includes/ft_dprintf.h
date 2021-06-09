/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:19:20 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/22 14:53:07 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_flag
{
	int		fd;
	int		minus;
	int		plus;
	int		space;
	char	zero;
	int		hashtag;
	int		width;
	int		prec;
	char	add_flags;
	char	type;
	size_t	tot_len;
}	t_flag;

//	*	formats

# define DEFAULT			"\e[0m"
# define BOLD				"\e[1m"
# define DIM				"\e[2m"
# define ITALIC				"\e[3m"
# define UNDERLINED			"\e[4m"
# define BLINK				"\e[5m"
# define REVERSE			"\e[7m"
# define HIDDEN				"\e[8m"

# define NO_FORMAT			"\e[22m"

//	*	text colors

# define NO_COLOR			"\e[39m"
# define BLACK				"\e[30m"
# define RED				"\e[31m"
# define GREEN				"\e[32m"
# define YELLOW				"\e[33m"
# define BLUE				"\e[34m"
# define MAGENTA			"\e[35m"
# define CYAN				"\e[36m"
# define LIGHT_GRAY			"\e[37m"
# define DARK_GRAY			"\e[90m"
# define LIGHT_RED			"\e[91m"
# define LIGHT_GREEN		"\e[92m"
# define LIGHT_YELLOW		"\e[93m"
# define LIGHT_BLUE			"\e[94m"
# define LIGHT_MAGENTA		"\e[95m"
# define LIGHT_CYAN			"\e[96m"
# define WHITE				"\e[97m"

//	*	background colors

# define BACK_NO_COLOR		"\e[49m"
# define BACK_BLACK			"\e[40m"
# define BACK_RED			"\e[41m"
# define BACK_GREEN			"\e[42m"
# define BACK_YELLOW		"\e[43m"
# define BACK_BLUE			"\e[44m"
# define BACK_MAGENTA		"\e[45m"
# define BACK_CYAN			"\e[46m"
# define BACK_LIGHT_GRAY	"\e[47m"
# define BACK_DARK_GRAY		"\e[100m"
# define BACK_LIGHT_RED		"\e[101m"
# define BACK_LIGHT_GREEN	"\e[102m"
# define BACK_LIGHT_YELLOW	"\e[103m"
# define BACK_LIGHT_BLUE	"\e[104m"
# define BACK_LIGHT_MAGENTA	"\e[105m"
# define BACK_LIGHT_CYAN	"\e[106m"
# define BACK_WHITE			"\e[107m"

int					ft_dprintf_atoi(const char *nptr);
char				*ft_dprintf_itoa(int n);
void				*ft_dprintf_memset(void *s, int c, size_t n);
char				*ft_dprintf_ptoa(unsigned long long ull, t_flag *flag);
void				ft_dprintf_putchar_fd(char c, t_flag *flag);
void				ft_dprintf_putstr_fd(char *str, t_flag *flag);
size_t				ft_dprintf_strlen(const char *s);
char				*ft_dprintf_utoa(unsigned int n);
char				*ft_dprintf_xtoa(unsigned int n, t_flag *flag);
int					ft_dprintf(int fd, const char *input, ...);
t_flag				*ft_dprintf_flag_init(t_flag *flag);
t_flag				*ft_dprintf_flag_reset(t_flag *flag);
int					ft_dprintf_get_add_flags(const char *input, \
									t_flag *flag);
int					ft_dprintf_get_first_flags(const char *input, \
									t_flag *flag, va_list args);
int					ft_dprintf_get_flag(const char *input, va_list args, \
									t_flag *flag);
int					ft_dprintf_get_prec(const char *input, va_list args, \
									t_flag *flag);
int					ft_dprintf_get_type(const char *input, t_flag *flag);
int					ft_dprintf_get_width(const char *input, va_list args, \
									t_flag *flag);
void				ft_dprintf_print_c(va_list args, t_flag *flag);
void				ft_dprintf_print_s(va_list args, t_flag *flag);
void				ft_dprintf_print_x(va_list args, t_flag *flag);
int					ft_dprintf_treat_flag(va_list args, t_flag *flag);
int					ft_dprintf_treat_input(const char *input, va_list args, \
									t_flag *flag);
int					ft_dprintf_print_normal(const char *input, int i, \
									t_flag *flag);
int					ft_dprintf_print_percent(int i, t_flag *flag);
void				ft_dprintf_print_p(va_list args, t_flag *flag);

#endif
