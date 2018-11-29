/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:16:06 by rojaguen          #+#    #+#             */
/*   Updated: 2018/11/07 15:50:01 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

t_file		*new_node()
{
	t_file *new;

	new = NULL;
	if (!(new = malloc(sizeof(*new))))
			exit (0);
	ft_bzero(new, sizeof(*new));
	new->next = NULL;
	return (new);
}

t_file		*add_link(t_file *lst, t_file *new)
{
	new->next = lst;
	lst = new;
	return (lst);
}

int		lst_is_sort(t_file *lst)
{
	while (lst->next)
	{
		if (ft_strcmp(lst->name, lst->next->name) > 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	free_lst(t_file **lst)
{
	t_file *tmp;

	tmp = *lst;
	while (tmp)
	{
		free((tmp)->name);
		free(tmp);
		if ((*lst)->next)
		*lst = (*lst)->next;
		tmp = *lst;
	}
}

t_file		*get_prev(t_file *lst, t_file *link)
{
	if (lst->id == link->id)
		return (lst);
	while (lst)
	{
		if (lst->next && lst->next->id == link->id)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
