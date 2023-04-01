/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:11:55 by samartin          #+#    #+#             */
/*   Updated: 2023/04/01 18:03:09 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dupes(t_bllist *lst)
{
	t_bllist	*i;
	t_bllist	*node;

	node = ft_bllst_first(lst);
	while (node)
	{
		i = ft_bllst_first(lst);
		while (i)
		{
			if (node != i && node->content == i->content)
				error_exit(103, lst, NULL);
			i = i->next;
		}
		node = node->next;
	}
}

void	check_int_sized(t_bllist *lst)
{
	lst = ft_bllst_first(lst);
	while (lst)
	{
		if (lst->content > __INT_MAX__ || lst->content < -(__INT_MAX__) - 1)
			error_exit(104, lst, NULL);
		lst = lst->next;
	}
}
