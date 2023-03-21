/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:38:52 by samartin          #+#    #+#             */
/*   Updated: 2023/02/03 14:05:20 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

/**
 * It returns the number of elements in a linked list.
 * 
 * @param lst A pointer to the first element of a linked list.
 * 
 * @return The length of the list.
 */
int	ft_lstsize(t_list *lst)
{
	unsigned int	lst_len;

	if (lst == NULL)
		return (0);
	lst_len = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		lst_len++;
	}
	return (lst_len);
}
