/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_utoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:38:29 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/22 14:01:34 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static size_t	get_size(unsigned int n)
{
	size_t			size;
	unsigned long	num;

	size = 0;
	num = n;
	while (num >= 10)
	{
		num /= 10;
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
	while (n >= 10)
	{
		n /= 10;
		pow++;
	}
	while (pow != 0)
	{
		pow_ten *= 10;
		pow--;
	}
	return (pow_ten);
}

static char	*out_fill(char *out, unsigned int num, unsigned int n)
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
		out[curr] = last + 48;
		curr++;
		prev_pow /= 10;
	}
	last = num / get_pow(num);
	num -= last * get_pow(num);
	out[curr] = last + 48;
	return (out);
}

char	*ft_dprintf_utoa(unsigned int n)
{
	unsigned int		num;
	char				*out;

	num = n;
	out = kemalloc(sizeof(char), (get_size(num) + 1));
	if (!out)
		return (NULL);
	out_fill(out, num, n);
	return (out);
}
