/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_get_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:37:16 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/22 11:37:16 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dprintf_get_type(const char *input, t_flag *flag)
{
	size_t	i;

	i = 0;
	if (input[i] == '%')
		flag->type = '%';
	else if (input[i] == 'c')
		flag->type = 'c';
	else if (input[i] == 's')
		flag->type = 's';
	else if (input[i] == 'p')
		flag->type = 'p';
	else if (input[i] == 'd')
		flag->type = 'd';
	else if (input[i] == 'i')
		flag->type = 'i';
	else if (input[i] == 'u')
		flag->type = 'u';
	else if (input[i] == 'x')
		flag->type = 'x';
	else if (input[i] == 'X')
		flag->type = 'X';
	else
		flag->type = -1;
	i++;
	return (i);
}
