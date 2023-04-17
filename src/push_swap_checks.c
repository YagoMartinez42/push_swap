/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:58:01 by samartin          #+#    #+#             */
/*   Updated: 2023/04/13 11:47:17 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (((t_idxd_node *)lst->content)->value > \
				((t_idxd_node *)lst->next->content)->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	check_dupes(t_list *lst)
{
	t_list	*i;
	t_list	*node;

	node = lst;
	while (node)
	{
		i = node->next;
		while (i)
		{
			if (((t_idxd_node *)node->content)->value == \
					((t_idxd_node *)i->content)->value)
				error_exit(103, lst, NULL);
			i = i->next;
		}
		node = node->next;
	}
}

void	check_int_sized(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node)
	{
		if (((t_idxd_node *)node->content)->value > __INT_MAX__ || \
				((t_idxd_node *)node->content)->value < -(__INT_MAX__) - 1)
			error_exit(104, lst, NULL);
		node = node->next;
	}
}
