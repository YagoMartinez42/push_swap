/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:58:01 by samartin          #+#    #+#             */
/*   Updated: 2023/04/19 12:31:36 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_idxlst *lst)
{
	while (lst && lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	check_dupes(t_idxlst *lst)
{
	t_idxlst	*i;
	t_idxlst	*node;

	node = lst;
	while (node)
	{
		i = node->next;
		while (i)
		{
			if (node->value == i->value)
				error_exit(103, lst, NULL);
			i = i->next;
		}
		node = node->next;
	}
}

void	check_int_sized(t_idxlst *lst)
{
	t_idxlst	*node;

	node = lst;
	while (node)
	{
		if (node->value > __INT_MAX__ || node->value < -(__INT_MAX__) - 1)
			error_exit(104, lst, NULL);
		node = node->next;
	}
}
