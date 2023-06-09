/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:58:01 by samartin          #+#    #+#             */
/*   Updated: 2023/05/09 15:05:00 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * The function checks if a linked list is sorted in ascending order.
 * 
 * @param lst A pointer to a linked list of integers.
 * 
 * @return The function returns an integer value of 0 or 1. If the list is
 * sorted in ascending order, the function returns 1. Otherwise, it returns 0.
 */
int	is_sorted(t_idxlst *lst)
{
	while (lst && lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

/**
 * The function checks for duplicates in a linked list and exits with an error
 * code if any are found.
 * 
 * @param lst A pointer to a linked list of integers.
 */
void	check_dupes(t_idxlst *lst)
{
	t_idxlst	*i;
	t_idxlst	*node;

	node = lst;
	while (node)
	{
		i = node->next;
		while (i)
		{
			if (node->value == i->value)
				error_exit(103, lst, NULL);
			i = i->next;
		}
		node = node->next;
	}
}

/**
 * The function checks if the values in a linked list are within the range of
 * an integer. Iterates through this linked list and checks if any of the
 * integers (stored with a larger than int type) exceed the maximum or minimum
 * value that can be represented by an int data type. If such is found, exits
 * with an error code.
 * 
 * @param lst A pointer to a linked list of integers.
 */
void	check_int_sized(t_idxlst *lst)
{
	t_idxlst	*node;

	node = lst;
	while (node)
	{
		if (node->value > __INT_MAX__ || node->value < -(__INT_MAX__) - 1)
			error_exit(104, lst, NULL);
		node = node->next;
	}
}
