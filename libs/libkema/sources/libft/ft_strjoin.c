/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 02:00:50 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/22 14:08:07 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	tot_len;
	char	*out;

	tot_len = ft_strlen(s1) + ft_strlen(s2);
	out = kemalloc(sizeof(char), (tot_len + 1));
	if (!out)
		return (NULL);
	ft_strcat(out, (char *)s1);
	ft_strcat(out, (char *)s2);
	return (out);
}
