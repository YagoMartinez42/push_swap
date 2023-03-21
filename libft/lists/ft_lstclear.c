/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:45:55 by samartin          #+#    #+#             */
/*   Updated: 2023/02/03 14:36:49 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

/**
 * Fully clears a list. It takes a pointer to a linked list, and a pointer to a
 * function to delete contents of a node. ft_lstdelone uses that function and
 * frees the node memory or just does the last if del is NULL.
 * 
 * @param lst a pointer to the first element of a linked list.
 * @param del a function that takes a pointer to a single element of the list,
 * deletes its content and frees it.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*swap;

	if (lst)
	{
		while (*lst)
		{
			swap = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = swap;
		}
	}
}
