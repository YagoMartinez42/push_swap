/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bllst_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:48:54 by samartin          #+#    #+#             */
/*   Updated: 2023/03/15 15:13:12 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

/**
 * Ft_lstlast returns the last element of a linked list.
 * 
 * @param lst A pointer to the first or any element of the list.
 * 
 * @return The last element of the list.
 */
t_bllist	*ft_bllst_last(t_bllist *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
