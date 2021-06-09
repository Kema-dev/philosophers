/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_print_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:36:50 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/22 14:02:46 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void	ft_dprintf_print_p_left(char *str, t_flag *flag)
{
	if (str[0] == '-')
	{
		ft_dprintf_putchar_fd('-', flag);
		str++;
	}
	ft_dprintf_putstr_fd("0x", flag);
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

static void	ft_dprintf_print_p_right(char *str, t_flag *flag)
{
	int	neg;

	neg = 0;
	if (str[0] == '-')
		neg = 1;
	while ((flag->width > flag->prec + neg) && \
						(flag->width > (int)ft_dprintf_strlen(str)))
		ft_dprintf_putchar_fd(' ', flag);
	ft_dprintf_putstr_fd("0x", flag);
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

void	ft_dprintf_print_p(va_list args, t_flag *flag)
{
	char	*str;

	str = ft_dprintf_ptoa(va_arg(args, unsigned long long), flag);
	flag->width -= 2;
	if ((str[0] == '0') && (!str[1]) && (flag->prec == 0))
		str[0] = 0;
	if (flag->minus == 0)
		ft_dprintf_print_p_left(str, flag);
	else
		ft_dprintf_print_p_right(str, flag);
	kemafree(str);
}
