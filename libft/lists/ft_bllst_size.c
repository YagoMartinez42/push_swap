/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bllst_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:02:36 by samartin          #+#    #+#             */
/*   Updated: 2023/03/16 16:04:49 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

/**
 * It returns the number of elements in a doubly linked list
 * 
 * @param lst The list to get the size of.
 * 
 * @return The size of the list.
 */
int	ft_bllst_size(t_bllist *lst)
{
	unsigned int	lst_len;

	if (!lst)
		return (0);
	lst = ft_bllst_first(lst);
	lst_len = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		lst_len++;
	}
	return (lst_len);
}
