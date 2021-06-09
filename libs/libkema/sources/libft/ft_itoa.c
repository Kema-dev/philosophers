/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 01:58:09 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/22 14:05:44 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t		size;
	long long	num;

	size = 0;
	num = n;
	if (num < 0)
		num *= -1;
	while (num >= 10)
	{
		num /= 10;
		size++;
	}
	return (size + 1);
}

static size_t	get_pow(long long n)
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

static char	*out_fill(char *out, long long num, int neg, int n)
{
	size_t	last;
	size_t	curr;
	size_t	prev_pow;

	last = 0;
	curr = 0;
	prev_pow = 0;
	if (neg == 1)
	{
		out[curr] = '-';
		curr++;
	}
	prev_pow = get_pow(num);
	while (curr != (get_size(n) - 1 + neg))
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

char	*ft_itoa(int n)
{
	long long	num;
	int			neg;
	char		*out;

	num = n;
	neg = 0;
	if (num < 0)
	{
		neg = 1;
		num *= -1;
	}
	out = kemalloc(sizeof(char), (get_size(num) + 1 + neg));
	if (!out)
		return (NULL);
	out_fill(out, num, neg, n);
	return (out);
}
