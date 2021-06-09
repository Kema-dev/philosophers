/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_ptoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:38:10 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/22 14:00:53 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static char	*treat_base(unsigned long long ull_save, char *out, int count)
{
	if (ull_save == 0)
	{
		out[0] = '0';
		return (out);
	}
	while (ull_save != 0)
	{
		if ((ull_save % 16) < 10)
			out[count - 1] = (ull_save % 16) + '0';
		else
			out[count - 1] = (ull_save % 16) + 87;
		ull_save /= 16;
		count--;
	}
	return (out);
}

char	*ft_dprintf_ptoa(unsigned long long ull, t_flag *flag)
{
	char				*out;
	unsigned long long	ull_save;
	int					count;

	out = 0;
	count = 0;
	ull_save = ull;
	while (ull != 0)
	{
		ull /= 16;
		count++;
	}
	out = kemalloc(sizeof(char), (count + 2 + 1));
	if (!out)
		return (NULL);
	out = treat_base(ull_save, out, count);
	(void)flag;
	return (out);
}
