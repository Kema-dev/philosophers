/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_print_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:37:06 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/22 11:37:06 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	ft_dprintf_print_c(va_list args, t_flag *flag)
{
	if (flag->minus != 0)
	{
		while (flag->width > 1)
			ft_dprintf_putchar_fd(' ', flag);
		ft_dprintf_putchar_fd(va_arg(args, int), flag);
	}
	else
	{
		ft_dprintf_putchar_fd(va_arg(args, int), flag);
		while (flag->width > 0)
			ft_dprintf_putchar_fd(' ', flag);
	}
}
