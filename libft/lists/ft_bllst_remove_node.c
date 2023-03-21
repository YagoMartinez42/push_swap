/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bllst_remove_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:23:44 by samartin          #+#    #+#             */
/*   Updated: 2023/03/17 11:28:15 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

/**
 * It removes a node from a doubly linked list.
 * 
 * @param node The node to be removed.
 * 
 * @return The first node of the list after the removal.
 */
t_bllist	*ft_bllst_remove_node(t_bllist *node)
{
	t_bllist	*aux;

	aux = NULL;
	if (node)
	{
		if (node->next)
		{
			node->next->prev = node->prev;
			aux = node->next;
		}
		if (node->prev)
		{
			node->prev->next = node->next;
			aux = node->prev;
		}
		free(node);
		if (aux)
			return (ft_bllst_first(aux));
	}
	return (NULL);
}
