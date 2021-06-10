/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:45:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/06/09 18:13:18 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_start_fight(t_philo **philo, pthread_mutex_t **fork, t_limits *limit)
{
	pthread_mutex_t	*wperm;
	pthread_t		tid;
	int				i;
	t_arg			*args;

	wperm = kemalloc(1, sizeof(pthread_mutex_t));
	if (!wperm)
		return (NOMEM);
	if (pthread_mutex_init(wperm, NULL) != SUCCESS)
		return (ERRMUTEX);
	args = kemalloc(1, sizeof(t_arg));
	if (!args)
		return (NOMEM);
	args->philo = philo;
	args->fork = fork;
	args->limit = limit;
	args->wperm = wperm;
	i = -1;
	while (++i < limit->nb_philo)
	{
		pthread_create(&tid, NULL, &philo_routine, (void *)args);
		pthread_detach(tid);
	}
	return (SUCCESS);
}

void	*philo_routine(void *args)
{
	t_arg	*arg;

	arg = (t_arg *)args;
	if (pthread_mutex_lock(arg->wperm) != SUCCESS)
		return ((void *)ERRMUTEX);
	if (pthread_mutex_unlock(arg->wperm) != SUCCESS)
		return ((void *)ERRMUTEX);
	sleep(100);
	return ((void *)SUCCESS);
}
