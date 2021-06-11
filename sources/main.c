/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:38:50 by jjourdan          #+#    #+#             */
/*   Updated: 2021/06/11 19:14:18 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_limits			*limit;
	pthread_mutex_t		**fork;
	t_philo				**philo;
	int					errnum;

	limit = kemalloc(1, sizeof(t_limits));
	if (!limit)
		return (kemaexit(NOMEM));
	if ((argc < 5) || (argc > 6))
		return (kemaexit(BADARG));
	errnum = philo_get_limits(limit, argv);
	if (errnum != SUCCESS)
		return (kemaexit(errnum));
	fork = NULL;
	errnum = philo_create_forks(&fork, limit);
	if (errnum != SUCCESS)
		return (kemaexit(errnum));
	philo = NULL;
	errnum = philo_create_philos(&philo, limit);
	if (errnum != SUCCESS)
		return (kemaexit(errnum));
	errnum = philo_start_fight(philo, fork, limit);
	if (errnum != SUCCESS)
		return (kemaexit(errnum));
	return (kemaexit(SUCCESS));
}
