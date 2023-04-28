/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index_updates.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:30:28 by samartin          #+#    #+#             */
/*   Updated: 2023/04/28 13:54:56 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_update_cur_pos(t_idxlst	*stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->cur_pos = i;
		stack = stack->next;
		i++;
	}
}

static int	ps_set_target(t_idxlst *stack_a, t_idxlst *node_b)
{
	int	target;
	int	low_idx;

	target = __INT_MAX__;
	low_idx = __INT_MAX__;
	while (stack_a)
	{
		if (stack_a->idx < low_idx)
			low_idx = stack_a->idx;
		if (node_b->idx > low_idx && node_b->idx < stack_a->idx \
				&& target > stack_a->idx)
			target = stack_a->cur_pos;
		stack_a = stack_a->next;
	}
	if (target == __INT_MAX__)
		target = low_idx;
	return (target);
}

void	ps_update_pos_idxs(t_idxlst *stack_a, t_idxlst *stack_b)
{
	ps_update_cur_pos(stack_a);
	ps_update_cur_pos(stack_b);
	while (stack_b)
	{
		stack_b->target_pos = ps_set_target(stack_a, stack_b);
		stack_b = stack_b->next;
	}
}

void	ps_update_cost(t_idxlst *stack_a, t_idxlst *stack_b)
{
	print_stacks(stack_a, stack_b);
}
