/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bllst_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:11:30 by samartin          #+#    #+#             */
/*   Updated: 2023/03/15 15:18:55 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

/**
 * It adds a new node to the front of a doubly linked list.
 * 
 * @param lst A pointer to a pointer to a t_bllist.
 * @param new The new node to start the list with.
 */
void	ft_bllst_add_front(t_bllist **lst, t_bllist *new)
{
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}
