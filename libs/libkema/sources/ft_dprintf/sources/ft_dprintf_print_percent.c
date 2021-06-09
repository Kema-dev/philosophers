/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_print_percent.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:36:45 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/22 11:36:45 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dprintf_print_percent(int i, t_flag *flag)
{
	if (flag->width > 0)
		i += flag->width;
	else
		i++;
	if (flag->minus != 0)
	{
		while (flag->width > 1)
			ft_dprintf_putchar_fd(flag->zero, flag);
		ft_dprintf_putchar_fd('%', flag);
	}
	else
	{
		ft_dprintf_putchar_fd('%', flag);
		while (flag->width > 0)
			ft_dprintf_putchar_fd(' ', flag);
	}
	return (i);
}
