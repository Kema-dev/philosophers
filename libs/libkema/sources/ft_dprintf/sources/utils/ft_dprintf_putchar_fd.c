/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_putchar_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:38:16 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/22 11:38:17 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	ft_dprintf_putchar_fd(char c, t_flag *flag)
{
	write(flag->fd, &c, 1);
	flag->tot_len++;
	flag->width--;
}
