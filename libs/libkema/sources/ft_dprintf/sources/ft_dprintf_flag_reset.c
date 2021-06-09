/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_flag_reset.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:37:38 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/22 11:37:38 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

t_flag	*ft_dprintf_flag_reset(t_flag *flag)
{
	flag->minus = -1;
	flag->plus = -1;
	flag->space = -1;
	flag->zero = ' ';
	flag->hashtag = -1;
	flag->width = -1;
	flag->prec = -1;
	flag->type = -1;
	flag->add_flags = -1;
	return (flag);
}
