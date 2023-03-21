/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bllst_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:40:19 by samartin          #+#    #+#             */
/*   Updated: 2023/03/15 15:13:15 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

/**
 * It creates a new node for a bi-directional linked list and returns a pointer
 * to it.
 * 
 * @param content The content (long integer) of the new node.
 * 
 * @return A pointer to a new node.
 */
t_bllist	*ft_bllst_new(long content)
{
	t_bllist	*new_node;

	new_node = (t_bllist *)malloc(sizeof (t_bllist));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
