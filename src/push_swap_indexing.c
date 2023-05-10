/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_indexing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:54:54 by samartin          #+#    #+#             */
/*   Updated: 2023/05/09 15:09:56 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * The function assigns an index to each node in a linked list based on their
 * value, with lowest values receiving the lowest index.
 * 
 * @param stack a pointer to a pointer to the head of the stack.
 */
void	index_stack(t_idxlst **stack)
{
	t_idxlst	*node;
	t_idxlst	*n2idx;
	size_t		stack_len;
	size_t		i;
	int			min;

	stack_len = ps_lst_size(*stack);
	i = 0;
	while (i < stack_len)
	{
		min = __INT_MAX__;
		node = *stack;
		while (node)
		{
			if (node->idx == -1 && node->value < min)
			{
				n2idx = node;
				min = node->value;
			}
			node = node->next;
		}
		if (n2idx)
			n2idx->idx = i;
		i++;
	}
}
