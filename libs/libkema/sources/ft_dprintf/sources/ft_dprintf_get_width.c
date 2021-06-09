/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_get_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:37:10 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/22 11:37:11 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dprintf_get_width(const char *input, va_list args, t_flag *flag)
{
	size_t	i;

	i = 0;
	if (((input[i] >= '0') && (input[i] <= '9')) || (input[i] == '*'))
	{
		if (input[i] != '*')
		{
			flag->width = ft_dprintf_atoi(&input[i]);
			while ((input[i] >= '0') && (input[i] <= '9'))
				i++;
		}
		else if ((flag->width == -1) && (input[i] == '*'))
		{
			flag->width = va_arg(args, int);
			i++;
		}
	}
	return (i);
}
