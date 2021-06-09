/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_xtoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:38:38 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/22 14:02:07 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static size_t	get_size(unsigned int n)
{
	size_t			size;
	unsigned long	num;

	size = 0;
	num = n;
	while (num >= 16)
	{
		num /= 16;
		size++;
	}
	return (size + 1);
}

static size_t	get_pow(unsigned int n)
{
	size_t	pow;
	size_t	pow_ten;

	pow = 0;
	pow_ten = 1;
	while (n >= 16)
	{
		n /= 16;
		pow++;
	}
	while (pow != 0)
	{
		pow_ten *= 16;
		pow--;
	}
	return (pow_ten);
}

static char	*out_fill(char *out, unsigned int num, \
							unsigned int n, char *base)
{
	size_t	last;
	size_t	curr;
	size_t	prev_pow;

	last = 0;
	curr = 0;
	prev_pow = get_pow(num);
	while (curr != (get_size(n) - 1))
	{
		last = num / prev_pow;
		num -= last * prev_pow;
		out[curr] = base[last];
		curr++;
		prev_pow /= 16;
	}
	last = num / get_pow(num);
	num -= last * get_pow(num);
	out[curr] = base[last];
	return (out);
}

char	*ft_dprintf_xtoa(unsigned int n, t_flag *flag)
{
	unsigned int		num;
	char				*out;
	char				*base;
	int					p;

	num = n;
	p = 0;
	base = "0123456789abcdef";
	if (flag->type == 'X')
		base = "0123456789ABCDEF";
	else if (flag->type == 'p')
		p = 2;
	out = kemalloc(sizeof(char), (get_size(num) + 1 + p));
	if (!out)
		return (NULL);
	if (flag->type == 'p')
	{
		out[0] = '0';
		out[1] = 'x';
		out += 2;
	}
	out_fill(out, num, n, base);
	return (out - p);
}
