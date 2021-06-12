/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:45:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/06/12 17:09:16 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_start_fight_2(t_limits *limit, t_philo **philo, t_arg *args)
{
	pthread_t		*tid;
	int				i;

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
	return (SUCCESS);
}

int	philo_start_fight_3(t_limits *limit, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < limit->nb_philo)
	{
		if (philo[i]->state == SATIATED)
		{
			i = -1;
			while (++i < limit->nb_philo)
			{
				if (philo[i]->state != SATIATED)
					break ;
			}
			if (i == limit->nb_philo)
			{
				usleep(150);
				return (SUCCESS);
			}
		}
		else if (philo_start_fight_4(philo, i) == SUCCESS)
			return (SUCCESS);
		i++;
		i = i % limit->nb_philo;
	}
	return (SUCCESS);
}

int	philo_start_fight_4(t_philo **philo, int i)
{
	if (philo[i]->state == DIED)
	{
		usleep(150);
		return (SUCCESS);
	}
	return (FAILURE);
}

int	philo_start_fight(t_philo **philo, pthread_mutex_t **fork, t_limits *limit)
{
	pthread_mutex_t	*wperm;
	t_arg			*args;
	int				errnum;

	wperm = kemalloc(1, sizeof(pthread_mutex_t));
	if (!wperm)
		return (NOMEM);
	if (pthread_mutex_init(wperm, NULL) != SUCCESS)
		return (ERRMUTEX);
	args = kemalloc(1, sizeof(t_arg));
	if (!args)
		return (NOMEM);
	args->fork = fork;
	args->limit = limit;
	args->wperm = wperm;
	errnum = philo_start_fight_2(limit, philo, args);
	if (errnum != SUCCESS)
		return (errnum);
	errnum = philo_start_fight_3(limit, philo);
	if (errnum != SUCCESS)
		return (errnum);
	return (SUCCESS);
}

void	philo_display_2(t_philo *philo, long time_disp)
{
	if (philo->state == THINKING)
		printf("%s%5ld%s philo %s%d%s is thinking\n", \
		LIGHT_BLUE, time_disp, DEFAULT, LIGHT_RED, philo->number, DEFAULT);
	else if (philo->state == REQ_FORK)
		printf("%s%5ld%s philo %s%d%s is thinking\n", \
		LIGHT_BLUE, time_disp, DEFAULT, LIGHT_RED, philo->number, DEFAULT);
	else if (philo->state == EATING)
		printf("%s%5ld%s philo %s%d%s is eating\n", \
		LIGHT_BLUE, time_disp, DEFAULT, LIGHT_RED, philo->number, DEFAULT);
	else if (philo->state == SLEEPING)
		printf("%s%5ld%s philo %s%d%s is sleeping\n", \
		LIGHT_BLUE, time_disp, DEFAULT, LIGHT_RED, philo->number, DEFAULT);
	else if (philo->state == DIED)
		printf("%s%5ld%s philo %s%d%s has died\n", \
		LIGHT_BLUE, time_disp, DEFAULT, LIGHT_RED, philo->number, DEFAULT);
	else if (philo->state == SATIATED)
		printf(\
		"%s%5ld%s philo %s%d%s is satiated, he already ate %d times !\n", \
		LIGHT_BLUE, time_disp, DEFAULT, LIGHT_RED, philo->number, DEFAULT, \
		philo->nb_lunches);
}
