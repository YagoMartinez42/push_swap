/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bllst_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:44:31 by samartin          #+#    #+#             */
/*   Updated: 2023/03/15 15:13:07 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

/**
 * It adds a new node to the end of a doubly linked list
 * 
 * @param lst A pointer to a pointer to a t_bllist.
 * @param new The new node to add to the list.
 */
void	ft_bllst_add_back(t_bllist **lst, t_bllist *new)
{
	if (lst)
	{
		if (*lst)
		{
			while ((*lst)->next)
				lst = &(*lst)->next;
			(*lst)->next = new;
			new->prev = *lst;
		}
		else
			*lst = new;
	}
}
