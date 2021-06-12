/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:28:31 by jjourdan          #+#    #+#             */
/*   Updated: 2021/06/12 17:09:00 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdbool.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdint.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

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

//	*	errors handlers

# define SUCCESS		0
# define STR_SUCCESS	"Operation success!"
# define FAILURE		1
# define STR_FAILURE	"Operation failure!"
# define BADARG			2
# define STR_BADARG		"Please correctly provide number_of_philosophers (>= 1), \
time_to_die (>= 0), time_to_eat (>= 0), time_to_sleep (>= 0), and maybe number_of_\
times_each_philosopher_must_eat (>= 0)!"
# define NOMEM			3
# define STR_NOMEM		"Not enough memory!"
# define ERRMUTEX		4
# define STR_ERRMUTEX	"Error while creating mutexes!"
# define ERRTHREAD		5
# define STR_ERRTHREAD	"Error while creating threads!"
# define ERRTIME		6
# define STR_ERRTIME	"Error while retrieving time!"
# define NOMEAL			7
# define STR_NOMEAL		"Provided number of meals is null or negative!"

# define THINKING		0
# define REQ_FORK		1
# define EATING			2
# define SLEEPING		3
# define DIED			4
# define SATIATED		5

# define NO_TAKE_FORK	0
# define TAKE_FORK		1

//	*	structs declarations

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_limits
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_eat;
	uint64_t			sec0;
	useconds_t			usec0;
}	t_limits;

typedef struct s_arg
{
	pthread_mutex_t		**fork;
	t_limits			*limit;
	pthread_mutex_t		*wperm;
}	t_arg;

typedef struct s_philo
{
	int					number;
	uint64_t			sec;
	useconds_t			usec;
	int					nb_lunches;
	int					state;
	int					nb_fork;
	t_arg				*arg;
}	t_philo;

//	*	functions prototypes

//	*	main.c
int						main(int argc, char **argv);

//	*	philo_1.c
int						philo_get_limits(t_limits *limit, char **argv);
int						philo_create_forks(pthread_mutex_t ***fork, \
							t_limits *limit);
int						philo_create_philos(t_philo ***philo, t_limits *limit);

//	*	philo_fight.c
int						philo_start_fight_2(t_limits *limit, t_philo **philo,
							t_arg *args);
int						philo_start_fight_3(t_limits *limit, t_philo **philo);
int						philo_start_fight_4(t_philo **philo, int i);
int						philo_start_fight(t_philo **philo, \
							pthread_mutex_t **fork, t_limits *limit);
void					philo_display_2(t_philo *philo, long time_disp);

//	*	philo_utils.c
int						philo_do_state_2(t_philo *philo);
int						philo_do_state(t_philo *philo);
int						philo_display(t_philo *philo, int fork_state);
void					*philo_routine(void *arg);

//	*	philo_libft.c
int						ft_atoi(const char *nptr);
void					*ft_calloc(size_t nmemb, size_t size);
void					ft_lstadd_front(t_list **alst, t_list *new);
void					*ft_memset(void *s, int c, size_t n);

//	*	kemalloc.c
void					*kemalloc(size_t nmemb, size_t size);
int						kemafree(void *ptr);
void					kemaclear(void);
int						kemaexit(int	errnum);

#endif
