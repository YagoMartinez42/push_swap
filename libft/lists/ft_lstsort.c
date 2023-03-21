/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:09:00 by samartin          #+#    #+#             */
/*   Updated: 2023/03/17 10:31:21 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

/**
 * It sorts a linked list of long integers in a configurable order.
 * 
 * @param lst a pointer to the first element of a linked list.
 * @param cmp a function to be added, that takes two ints and returns 0 if they
 * are not in the expected order.
 * 
 * @return A pointer to the first element of the sorted list.
 */
t_list	*ft_lstsort(t_list *lst, int (*cmp)(long, long))
{
	t_list	*cur;
	t_list	*past_last;
	void	*swp;

	if (lst && lst->next && cmp)
	{
		cur = lst;
		past_last = NULL;
		while (cur->next != past_last)
		{
			while (cur->next != past_last)
			{
				if (!(cmp(*(long *)cur->content, *(long *)cur->next->content)))
				{
					swp = cur->content;
					cur->content = cur->next->content;
					cur->next->content = swp;
				}
				cur = cur->next;
			}
			past_last = cur;
			cur = lst;
		}
	}
	return (lst);
}
