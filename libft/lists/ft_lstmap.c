/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:03:56 by samartin          #+#    #+#             */
/*   Updated: 2023/02/03 14:22:03 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

/**
 * It takes a list, applies a function to each element of the list, and returns
 * a new list with the results of the function.
 * 
 * @param lst a pointer to the first node of a linked list.
 * @param f a function that takes a void * and returns a void *, to apply to any
 * type of content.
 * @param del a function that takes a pointer to a single element of the list
 * and frees the memory of that element. Used in case the lists construction
 * fails.
 * 
 * @return A pointer to the first element of the new list.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*settled_node;
	t_list	*node;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (NULL);
	settled_node = head;
	while (lst->next != NULL)
	{
		lst = lst->next;
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		settled_node->next = node;
		settled_node = node;
	}
	return (head);
}
