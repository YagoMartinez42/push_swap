/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:52:03 by samartin          #+#    #+#             */
/*   Updated: 2023/02/03 14:39:52 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

/**
 * It adds a new element to the end of a linked list
 * 
 * @param lst A pointer to a pointer to the first element of a linked list.
 * @param new the new element to add to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
		{
			while ((*lst)->next != NULL)
				lst = &(*lst)->next;
			(*lst)->next = new;
		}
		else
			*lst = new;
	}
}
