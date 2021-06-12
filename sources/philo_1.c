/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:25:49 by jjourdan          #+#    #+#             */
/*   Updated: 2021/06/12 15:12:48 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_get_limits(t_limits *limit, char **argv)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (ERRTIME);
	limit->sec0 = time.tv_sec;
	limit->usec0 = time.tv_usec;
	limit->nb_philo = ft_atoi(argv[1]);
	if (limit->nb_philo <= 1)
		return (BADARG);
	limit->time_to_die = ft_atoi(argv[2]);
	if (limit->time_to_die <= 0)
		return (BADARG);
	limit->time_to_eat = ft_atoi(argv[3]);
	if (limit->time_to_eat <= 0)
		return (BADARG);
	limit->time_to_sleep = ft_atoi(argv[4]);
	if (limit->time_to_sleep <= 0)
		return (BADARG);
	if (argv[5])
	{
		limit->nb_eat = ft_atoi(argv[5]);
		if (limit->nb_eat <= 0)
			return (BADARG);
	}
	else
		limit->nb_eat = INT_MAX;
	return (SUCCESS);
}

int	philo_create_forks(pthread_mutex_t ***fork, t_limits *limit)
{
	int	i;

	(*fork) = kemalloc(limit->nb_philo + 1, sizeof(pthread_mutex_t *));
	if (!(*fork))
		return (kemaexit(NOMEM));
	i = -1;
	while (++i < (limit->nb_philo))
	{
		(*fork)[i] = kemalloc(1, sizeof(pthread_mutex_t));
		if (pthread_mutex_init((*fork)[i], NULL) != 0)
			return (ERRMUTEX);
	}
	return (SUCCESS);
}

int	philo_create_philos(t_philo ***philo, t_limits *limit)
{
	struct timeval	time;
	int				i;

	*philo = kemalloc(limit->nb_philo, sizeof(t_philo *) + 1);
	if (!*philo)
		return (NOMEM);
	i = -1;
	while (++i < limit->nb_philo)
	{
		(*philo)[i] = kemalloc(1, sizeof(t_philo));
		if (!(*philo)[i])
			return (NOMEM);
		(*philo)[i]->number = i + 1;
		if (gettimeofday(&time, NULL) != 0)
			return (ERRTIME);
		(*philo)[i]->sec = time.tv_sec;
		(*philo)[i]->usec = time.tv_usec;
		(*philo)[i]->nb_lunches = 0;
		(*philo)[i]->state = 0;
		(*philo)[i]->nb_fork = 0;
	}
	return (SUCCESS);
}
