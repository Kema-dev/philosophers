/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:45:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/06/11 17:51:24 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_start_fight(t_philo **philo, pthread_mutex_t **fork, t_limits *limit)
{
	pthread_mutex_t	*death;
	pthread_mutex_t	*wperm;
	pthread_t		*tid;
	int				i;
	t_arg			*args;

	wperm = kemalloc(1, sizeof(pthread_mutex_t));
	if (!wperm)
		return (NOMEM);
	if (pthread_mutex_init(wperm, NULL) != SUCCESS)
		return (ERRMUTEX);
	death = kemalloc(1, sizeof(pthread_mutex_t));
	if (!death)
		return (NOMEM);
	if (pthread_mutex_init(death, NULL) != SUCCESS)
		return (ERRMUTEX);
	args = kemalloc(1, sizeof(t_arg));
	if (!args)
		return (NOMEM);
	args->fork = fork;
	args->limit = limit;
	args->wperm = wperm;
	args->death = death;
	tid = kemalloc(limit->nb_philo + 1, sizeof(pthread_t));
	if (!tid)
		return (NOMEM);
	i = -1;
	while (++i < limit->nb_philo)
	{
		philo[i]->arg = args;
		if (pthread_create(&tid[i], NULL, &philo_routine, \
					(void *)philo[i]) != SUCCESS)
			return (ERRTHREAD);
		usleep(50);
	}
	if (limit->nb_philo < INT_MAX)
	{
		i = -1;
		while (++i < limit->nb_philo)
		{
			if (pthread_join(tid[i], NULL) != SUCCESS)
				return (ERRTHREAD);
		}
	}
	else
	{
		i = 0;
		while (i < limit->nb_philo)
		{
			if (philo[i]->state == DIED)
				return (DIED);
			i++;
			i = i % limit->nb_philo;
		}
	}
	return (SUCCESS);
}

int	philo_display(t_philo *philo, int fork_state)
{
	struct timeval	time;
	long			time_disp;

	if (gettimeofday(&time, NULL) != 0)
		return (ERRTIME);
	time_disp = (time.tv_sec * 1000000 + time.tv_usec \
				- philo->arg->limit->sec0 * 1000000 - philo->arg->limit->usec0) / 1000;
	if (pthread_mutex_lock(philo->arg->wperm) != SUCCESS)
		return (ERRMUTEX);
	if (fork_state != NO_TAKE_FORK)
		ft_dprintf(STDOUT_FILENO, "\e[94m%5ld\e[0m philo \e[91m%d\e[0m has taken a fork\n", time_disp, philo->number);
	else
	{
		if (philo->state == THINKING)
			ft_dprintf(STDOUT_FILENO, "\e[94m%5ld\e[0m philo \e[91m%d\e[0m is thinking\n", time_disp, philo->number);
		else if (philo->state == REQ_FORK)
			ft_dprintf(STDOUT_FILENO, "\e[94m%5ld\e[0m philo \e[91m%d\e[0m is thinking\n", time_disp, philo->number);
		else if (philo->state == EATING)
			ft_dprintf(STDOUT_FILENO, "\e[94m%5ld\e[0m philo \e[91m%d\e[0m is eating\n", time_disp, philo->number);
		else if (philo->state == SLEEPING)
			ft_dprintf(STDOUT_FILENO, "\e[94m%5ld\e[0m philo \e[91m%d\e[0m is sleeping\n", time_disp, philo->number);
		else if (philo->state == DIED)
			ft_dprintf(STDOUT_FILENO, "\e[94m%5ld\e[0m philo \e[91m%d\e[0m has died\n", time_disp, philo->number);
		else if (philo->state == SATIATED)
			ft_dprintf(STDOUT_FILENO, "\e[94m%5ld\e[0m philo \e[91m%d\e[0m is satiated, he already ate %d times !\n", time_disp, philo->number, philo->nb_lunches);
	}
	if (pthread_mutex_unlock(philo->arg->wperm) != SUCCESS)
		return (ERRMUTEX);
	return (SUCCESS);
}

int	philo_do_state(t_philo *philo)
{
	struct timeval	time;

	if (philo->state == SLEEPING)
	{
		philo_display(philo, NO_TAKE_FORK);
		usleep(philo->arg->limit->time_to_sleep * 1000);
	}
	else if (philo->state == REQ_FORK)
	{
		philo_display(philo, NO_TAKE_FORK);
		if (pthread_mutex_lock(philo->arg->fork[philo->number - 1]) != SUCCESS)
			return (ERRMUTEX);
		philo_display(philo, TAKE_FORK);
		if (pthread_mutex_lock(philo->arg->fork[philo->number % philo->arg->limit->nb_philo]) != SUCCESS)
			return (ERRMUTEX);
		philo_display(philo, TAKE_FORK);
		philo->state += 1;
		philo_display(philo, NO_TAKE_FORK);
		usleep(philo->arg->limit->time_to_eat * 1000);
		if (gettimeofday(&time, NULL) != 0)
			return (ERRTIME);
		philo->nb_lunches += 1;
		if (philo->nb_lunches >= philo->arg->limit->nb_eat)
		{
			philo->state = SATIATED;
			philo_display(philo, NO_TAKE_FORK);
			if (pthread_mutex_unlock(philo->arg->fork[philo->number % philo->arg->limit->nb_philo]) != SUCCESS)
				return (ERRMUTEX);
			if (pthread_mutex_unlock(philo->arg->fork[philo->number - 1]) != SUCCESS)
				return (ERRMUTEX);
			return (SUCCESS);
		}
		philo->sec = time.tv_sec;
		philo->usec = time.tv_usec;
		if (pthread_mutex_unlock(philo->arg->fork[philo->number % philo->arg->limit->nb_philo]) != SUCCESS)
			return (ERRMUTEX);
		if (pthread_mutex_unlock(philo->arg->fork[philo->number - 1]) != SUCCESS)
			return (ERRMUTEX);
	}
	else if (philo->state == DIED)
		philo_display(philo, NO_TAKE_FORK);
	return (SUCCESS);
}

void	*philo_routine(void *philos)
{
	t_philo			*philo;
	struct timeval	time;
	long			time_since;

	philo = (t_philo *)philos;
	while ((philo->state != DIED) && (philo->state != SATIATED))
	{
		if (pthread_mutex_lock(philo->arg->death) != SUCCESS)
			return ((void *)ERRMUTEX);
		if (pthread_mutex_unlock(philo->arg->death) != SUCCESS)
			return ((void *)ERRMUTEX);
		if (gettimeofday(&time, NULL) != 0)
			return ((void *)ERRTIME);
		time_since = (time.tv_sec * 1000000 + time.tv_usec \
					- philo->sec * 1000000 - philo->usec) / 1000;
		philo->state = (philo->state + 1) % 4;
		if (time_since >= philo->arg->limit->time_to_die)
		{
			if (pthread_mutex_lock(philo->arg->death) != SUCCESS)
				return ((void *)ERRMUTEX);
			philo->state = DIED;
		}
		philo_do_state(philo);
	}
	return ((void *)FAILURE);
}
