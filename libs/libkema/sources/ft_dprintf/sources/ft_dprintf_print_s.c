/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_print_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:36:40 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/22 11:36:41 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void	ft_dprintf_print_s_left(char *str, t_flag *flag)
{
	if ((int)ft_dprintf_strlen(str) < flag->prec)
		flag->prec = (int)ft_dprintf_strlen(str);
	while ((str[0] != 0) && (flag->prec > 0))
	{
		ft_dprintf_putchar_fd(str[0], flag);
		str++;
		flag->prec--;
	}
	while (flag->width > 0)
		ft_dprintf_putchar_fd(' ', flag);
}

static void	ft_dprintf_print_s_right(char *str, t_flag *flag)
{
	if ((int)ft_dprintf_strlen(str) < flag->prec)
		flag->prec = (int)ft_dprintf_strlen(str);
	while (flag->width > flag->prec)
		ft_dprintf_putchar_fd(' ', flag);
	while ((str[0] != 0) && (flag->prec > 0))
	{
		ft_dprintf_putchar_fd(str[0], flag);
		str++;
		flag->prec--;
	}
}

void	ft_dprintf_print_s(va_list args, t_flag *flag)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	if (flag->prec < 0)
		flag->prec = ft_dprintf_strlen(str);
	if (flag->minus == 0)
		ft_dprintf_print_s_left(str, flag);
	else
		ft_dprintf_print_s_right(str, flag);
}
