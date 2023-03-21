/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bllst_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:53:30 by samartin          #+#    #+#             */
/*   Updated: 2023/03/16 16:01:41 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

/**
 * Iterate through the list and apply the function to each element
 * 
 * @param lst The list to iterate over.
 * @param f The function to be applied to each element of the list.
 */
void	ft_bllst_iter(t_bllist *lst, void (*f)(long))
{
	if (lst)
		lst = ft_bllst_first(lst);
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}
