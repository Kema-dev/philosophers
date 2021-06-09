/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_treat_flag.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:36:30 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/22 11:36:31 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dprintf_treat_flag(va_list args, t_flag *flag)
{
	if (flag->type == '%')
		ft_dprintf_print_percent(1, flag);
	else if (flag->type == 'c')
		ft_dprintf_print_c(args, flag);
	else if ((flag->type == 'x') || (flag->type == 'X') || (flag->type == 'u') \
								 || (flag->type == 'd') || (flag->type == 'i'))
		ft_dprintf_print_x(args, flag);
	else if (flag->type == 'p')
		ft_dprintf_print_p(args, flag);
	else if (flag->type == 's')
		ft_dprintf_print_s(args, flag);
	else
		return (-1);
	return (0);
}
