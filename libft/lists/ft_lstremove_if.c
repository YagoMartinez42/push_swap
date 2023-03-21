/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:59:33 by samartin          #+#    #+#             */
/*   Updated: 2023/02/03 14:22:06 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

/**
 * It removes all nodes from a linked list that have a content that matches the
 * data_ref parameter.
 * 
 * @param lst a pointer to a pointer to the first element of a linked list.
 * @param data_ref the reference data to compare to.
 * @param cmp a function that compares two elements of the list. Returns 0 if
 * the contents are equal.
 */
void	ft_lstremove_if(t_list **lst, void *data_ref, int (*cmp)(void *, \
void *))
{
	t_list	*curr;
	t_list	*prev;

	prev = NULL;
	curr = *lst;
	while (curr && cmp)
	{
		if (cmp(curr->content, data_ref) == 0)
		{
			if (prev)
				prev->next = curr->next;
			else
				*lst = curr->next;
			free(curr);
			if (prev)
				curr = prev->next;
			else
				curr = *lst;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}
