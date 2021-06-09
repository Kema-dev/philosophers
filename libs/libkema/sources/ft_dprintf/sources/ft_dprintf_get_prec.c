/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_get_prec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:37:20 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/22 11:37:20 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dprintf_get_prec(const char *input, va_list args, t_flag *flag)
{
	size_t	i;

	i = 0;
	if (input[i] == '.')
	{
		i++;
		if (input[i] != '*')
		{
			flag->prec = ft_dprintf_atoi(&input[i]);
			while ((input[i] >= '0') && (input[i] <= '9'))
				i++;
		}
		else
		{
			flag->prec = va_arg(args, int);
			i++;
		}
	}
	return (i);
}
