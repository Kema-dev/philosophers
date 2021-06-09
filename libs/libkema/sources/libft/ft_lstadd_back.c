/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:00:39 by jjourdan          #+#    #+#             */
/*   Updated: 2020/12/05 15:41:19 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*buf;

	if (!new || !alst)
		return ;
	buf = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (buf->next)
			buf = buf->next;
		buf->next = new;
	}
}
