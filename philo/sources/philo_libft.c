/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:43:37 by jjourdan          #+#    #+#             */
/*   Updated: 2021/06/12 16:46:38 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	n;
	int				neg;

	neg = 1;
	if (!nptr)
		return (0);
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	n = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (n > n * 10 + *nptr - '0')
			return (0);
		n = n * 10 + *nptr - '0';
		nptr++;
	}
	n *= neg;
	return (n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;

	tab = malloc(size * nmemb);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, size * nmemb);
	return (tab);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	if (!s)
		return (NULL);
	p = (unsigned char *)s;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (s);
}
