/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kemalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 08:47:22 by jjourdan          #+#    #+#             */
/*   Updated: 2021/06/11 16:31:02 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libkema.h"

static t_list	**kemainit(void)
{
	static t_list	*mem;

	return (&mem);
}

void	*kemalloc(size_t nmemb, size_t size)
{
	t_list	*new_mem;
	void	*elem;

	if ((nmemb <= 0) || (size <= 0))
		return (NULL);
	elem = ft_calloc(nmemb, size);
	if (!elem)
		return (NULL);
	new_mem = ft_calloc(1, sizeof(t_list));
	if (!new_mem)
	{
		free (elem);
		return (NULL);
	}
	new_mem->content = elem;
	new_mem->next = NULL;
	ft_lstadd_front(kemainit(), new_mem);
	return (elem);
}

int	kemafree(void *ptr)
{
	t_list	**beg;
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	prev = NULL;
	beg = kemainit();
	curr = *beg;
	while (curr)
	{
		next = curr->next;
		if (curr->content == ptr)
		{
			free(ptr);
			free(curr);
			if (prev)
				prev->next = next;
			else
				*beg = next;
			return (EXIT_SUCCESS);
		}
		prev = curr;
		curr = curr->next;
	}
	return (EXIT_FAILURE);
}

void	kemaclear(void)
{
	t_list	**beg;
	t_list	*mem;
	t_list	*buf;

	beg = kemainit();
	mem = *beg;
	while (mem)
	{
		buf = mem->next;
		free(mem->content);
		free(mem);
		mem = buf;
	}
	beg = NULL;
}

int	kemaexit(int	errnum)
{
	char	*tab[15];

	tab[0] = STR_SUCCESS;
	tab[1] = STR_FAILURE;
	tab[2] = STR_BADARG;
	tab[2] = STR_NOMEM;
	tab[2] = STR_ERRMUTEX;
	tab[2] = STR_ERRTHREAD;
	tab[2] = STR_ERRMUTEX;
	kemaclear();
	if (errnum > 1)
		ft_dprintf(STDERR_FILENO, "%s\n", tab[errnum]);
	return (errnum);
}
