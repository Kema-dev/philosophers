/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:36:14 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/22 14:03:29 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dprintf(int fd, const char *input, ...)
{
	va_list		args;
	t_flag		*flag;
	int			val;

	val = 0;
	flag = kemalloc(1, sizeof(t_flag));
	if (!flag)
		return (-1);
	flag->fd = fd;
	va_start(args, input);
	val = ft_dprintf_treat_input(input, args, flag);
	va_end(args);
	if (val == 0)
		val = flag->tot_len;
	kemafree(flag);
	return (val);
}
