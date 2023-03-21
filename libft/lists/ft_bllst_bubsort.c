/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bllst_bubsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:07:01 by samartin          #+#    #+#             */
/*   Updated: 2023/03/21 14:54:13 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"
#include "../libft.h"
/**
 * Swap the node with the next node in the list.
 * 
 * @param node the node to swap
 */
void	swap_nodes(t_bllist *node1, t_bllist *node2)
{
	t_bllist *swp;
	
	if (node1 && node2)
	{
		swp = node1->next;
		node1->next = node2->next;
		node2->next = swp;
		if (node1->next)
			node1->next->prev = node1;
		if (node2->next)
			node2->next->prev = node2;
		swp = node1->prev;
		node1->prev = node2->prev;
		node2->prev = swp;
		if (node1->prev)
			node1->prev->next = node1;
		if (node2->prev)
			node2->prev->next = node2;
	}
}

/**
 * It takes a doubly linked list and a comparison function, and returns a
 * sorted list.
 * 
 * @param lst The list to sort.
 * @param cmp A function that takes two longs and returns a long.
 * 
 * @return A pointer to the first node of the sorted list.
 */
t_bllist	*ft_bllst_bubsort(t_bllist *cur, int (*cmp)(long, long))
{
	t_bllist	*past_last;

	if (!cur)
		return (NULL);
	cur = ft_bllst_first(cur);
	if (cur->next && cmp)
	{
		past_last = NULL;
		while (cur->next != past_last)
		{
			while (cur->next != past_last)
			{
				if (!(cmp(cur->content, cur->next->content)))
					swap_nodes(cur, cur->next);
				else
					cur = cur->next;
			}
			past_last = cur;
			cur = ft_bllst_first(cur);
		}
	}
	return (cur);
}
