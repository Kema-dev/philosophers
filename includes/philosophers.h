/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:28:31 by jjourdan          #+#    #+#             */
/*   Updated: 2021/06/10 14:26:06 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_PROJECT_H
# define MY_PROJECT_H

# include "../libs/libkema/includes/libkema.h"
# include <stdbool.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

//	*	errors handlers

# define SUCCESS		0
# define STR_SUCCESS	"Operation success!"
# define FAILURE		1
# define STR_FAILURE	"Operation failure!"
# define BADARG			2
# define STR_BADARG		"Please correctly provide number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, and maybe number_of_times_each_philosopher_must_eat!"
# define NOMEM			3
# define STR_NOMEM		"Not enough memory!"
# define ERRMUTEX		4
# define STR_ERRMUTEX		"Error while creating mutexes!"
# define ERRTHREAD		5
# define STR_ERRTHREAD	"Error while creating threads!"
# define ERRTIME		6
# define STR_ERRTIME	"Error while retrieving time!"

# define THINKING		0
# define REQ_FORK		1
# define EATING			2
# define SLEEPING		3
# define DIED			4

# define NO_TAKE_FORK	0
# define TAKE_FORK		1

//	*	structs declarations

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
	pthread_mutex_t		*death;
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
int						philo_create_forks(pthread_mutex_t ***fork, t_limits *limit);
int						philo_create_philos(t_philo ***philo, t_limits *limit);

//	*	philo_fight.c
int						philo_start_fight(t_philo **philo, pthread_mutex_t **fork, t_limits *limit);
int						philo_display(t_philo *philo, int fork_state);
int						philo_do_state(t_philo *philo);
void					*philo_routine(void *arg);

#endif
