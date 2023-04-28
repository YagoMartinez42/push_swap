/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:26:30 by samartin          #+#    #+#             */
/*   Updated: 2023/04/28 14:19:03 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lst_add_back(t_idxlst **lst, t_idxlst *newnode)
{
	if (lst)
	{
		if (*lst)
		{
			while ((*lst)->next)
				lst = &((*lst)->next);
			(*lst)->next = newnode;
		}
		else
			*lst = newnode;
	}
}

t_idxlst	*ps_lst_clear(t_idxlst *lst)
{
	t_idxlst	*swap;

	while (lst)
	{
		swap = lst->next;
		free(lst);
		lst = swap;
	}
	return (lst);
}

t_idxlst	*ps_lst_new(long value)
{
	t_idxlst	*new_node;

	new_node = (t_idxlst *)malloc(sizeof (t_idxlst));
	if (new_node == NULL)
		return (NULL);
	ft_bzero(new_node, sizeof(t_idxlst));
	new_node->value = value;
	new_node->idx = -1;
	new_node->next = NULL;
	return (new_node);
}

int	ps_lst_size(t_idxlst *lst)
{
	int	lst_len;

	if (!lst)
		return (0);
	lst_len = 1;
	while (lst->next)
	{
		lst = lst->next;
		lst_len++;
	}
	return (lst_len);
}
