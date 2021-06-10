/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:28:31 by jjourdan          #+#    #+#             */
/*   Updated: 2021/06/10 11:57:24 by jjourdan         ###   ########lyon.fr   */
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

//	*	structs declarations

typedef struct s_philo
{
	int					number;
	uint64_t			sec;
	useconds_t			usec;
	int					nb_lunches;
	int					state; // * 0 = think ; 1 = eat ; 2 = sleep
	int					nb_fork;
}	t_philo;

typedef struct s_limits
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_eat;
}	t_limits;

typedef struct s_arg
{
	t_philo				**philo;
	pthread_mutex_t		**fork;
	t_limits			*limit;
	pthread_mutex_t		*wperm;
}	t_arg;

//	*	functions prototypes

//	*	main.c
int						main(int argc, char **argv);

//	*	philo_1.c
int						philo_get_limits(t_limits *limit, char **argv);
int						philo_create_forks(pthread_mutex_t **fork, t_limits *limit);
int						philo_create_philos(t_philo ***philo, t_limits *limit);

//	*	philo_fight.c
int						philo_start_fight(t_philo **philo, pthread_mutex_t **fork, t_limits *limit);
void					*philo_routine(void *arg);

#endif
