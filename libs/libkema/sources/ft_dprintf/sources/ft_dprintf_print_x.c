/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_print_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:36:36 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/22 14:03:09 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void	ft_dprintf_print_x_left(char *str, t_flag *flag)
{
	if (str[0] == '-')
	{
		ft_dprintf_putchar_fd('-', flag);
		str++;
	}
	while (flag->prec > (int)ft_dprintf_strlen(str))
	{
		ft_dprintf_putchar_fd('0', flag);
		flag->prec--;
	}
	while (str[0] != 0)
	{
		ft_dprintf_putchar_fd(str[0], flag);
		str++;
	}
	while (flag->width > 0)
		ft_dprintf_putchar_fd(' ', flag);
}

static void	ft_dprintf_print_x_zero(char *str, t_flag *flag)
{
	if ((str[0] == '-') && (flag->zero != ' '))
	{
		ft_dprintf_putchar_fd('-', flag);
		str++;
	}
	while (flag->width > (int)ft_dprintf_strlen(str))
		ft_dprintf_putchar_fd(flag->zero, flag);
	if (str[0] == '-')
	{
		ft_dprintf_putchar_fd('-', flag);
		str++;
	}
	while (str[0] != 0)
	{
		ft_dprintf_putchar_fd(str[0], flag);
		str++;
	}
}

static void	ft_dprintf_print_x_right(char *str, t_flag *flag)
{
	int	neg;

	neg = 0;
	if (str[0] == '-')
		neg = 1;
	while ((flag->width > flag->prec + neg) && \
						(flag->width > (int)ft_dprintf_strlen(str)))
		ft_dprintf_putchar_fd(' ', flag);
	if (str[0] == '-')
	{
		ft_dprintf_putchar_fd('-', flag);
		str++;
	}
	while (flag->prec > (int)ft_dprintf_strlen(str))
	{
		ft_dprintf_putchar_fd('0', flag);
		flag->prec--;
	}
	while (str[0] != 0)
	{
		ft_dprintf_putchar_fd(str[0], flag);
		str++;
	}
}

void	ft_dprintf_print_x(va_list args, t_flag *flag)
{
	char	*str;

	str = NULL;
	if ((flag->type == 'x') || (flag->type == 'X'))
		str = ft_dprintf_xtoa(va_arg(args, int), flag);
	else if ((flag->type == 'd') || (flag->type == 'i'))
		str = ft_dprintf_itoa(va_arg(args, int));
	else if (flag->type == 'u')
		str = ft_dprintf_utoa(va_arg(args, int));
	if ((str[0] == '0') && (flag->prec == 0))
	{
		while (flag->width > 0)
			ft_dprintf_putchar_fd(' ', flag);
	}
	else if (flag->minus == 0)
		ft_dprintf_print_x_left(str, flag);
	else
	{
		if (flag->prec < 0)
			ft_dprintf_print_x_zero(str, flag);
		else
			ft_dprintf_print_x_right(str, flag);
	}
	kemafree(str);
}
