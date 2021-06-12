/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:35:13 by jjourdan          #+#    #+#             */
/*   Updated: 2021/06/12 17:18:17 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_do_state_2(t_philo *philo)
{
	struct timeval	time;

	philo_display(philo, TAKE_FORK);
	philo->state += 1;
	philo_display(philo, NO_TAKE_FORK);
	if (gettimeofday(&time, NULL) != 0)
		return (ERRTIME);
	philo->sec = time.tv_sec;
	philo->usec = time.tv_usec;
	usleep(philo->arg->limit->time_to_eat * 1000);
	philo->nb_lunches += 1;
	if (philo->nb_lunches >= philo->arg->limit->nb_eat)
	{
		philo->state = SATIATED;
		philo_display(philo, NO_TAKE_FORK);
	}
	if (pthread_mutex_unlock(philo->arg->fork[philo->number % \
	philo->arg->limit->nb_philo]) != SUCCESS)
		return (ERRMUTEX);
	if (pthread_mutex_unlock(philo->arg->fork[philo->number - 1]) \
	!= SUCCESS)
		return (ERRMUTEX);
	return (SUCCESS);
}

int	philo_do_state(t_philo *philo)
{
	int				errnum;

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
		if (pthread_mutex_lock(philo->arg->fork[philo->number % \
		philo->arg->limit->nb_philo]) != SUCCESS)
			return (ERRMUTEX);
		errnum = philo_do_state_2(philo);
		if (errnum != SUCCESS)
			return (errnum);
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
		if (gettimeofday(&time, NULL) != 0)
			return ((void *)ERRTIME);
		time_since = (time.tv_sec * 1000000 + time.tv_usec \
					- philo->sec * 1000000 - philo->usec) / 1000;
		philo->state = (philo->state + 1) % 4;
		if (time_since > philo->arg->limit->time_to_die)
		{
			if (pthread_mutex_lock(philo->arg->wperm) != SUCCESS)
				return ((void *)ERRMUTEX);
			philo->state = DIED;
			printf("%s%5lld%s philo %s%d has died\n", \
LIGHT_BLUE, (time.tv_sec * 1000000 + time.tv_usec - philo->arg->limit->sec0 * \
1000000 - philo->arg->limit->usec0) / 1000, DEFAULT, LIGHT_RED, philo->number);
			return ((void *)FAILURE);
		}
		philo_do_state(philo);
	}
	return ((void *)FAILURE);
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
		printf("%s%5ld%s philo %s%d%s has taken a fork\n", \
			LIGHT_BLUE, time_disp, DEFAULT, LIGHT_RED, philo->number, DEFAULT);
	else
		philo_display_2(philo, time_disp);
	if (pthread_mutex_unlock(philo->arg->wperm) != SUCCESS)
		return (ERRMUTEX);
	return (SUCCESS);
}
