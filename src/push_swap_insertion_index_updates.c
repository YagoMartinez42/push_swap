/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_insertion_index_updates.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:30:28 by samartin          #+#    #+#             */
/*   Updated: 2023/05/08 15:28:02 by samartin         ###   ########.fr       */
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
	int			low_idx;
	int			low_idx_pos;
	t_idxlst	*target_node;

	target_node = NULL;
	low_idx = __INT_MAX__;
	while (stack_a)
	{
		if (stack_a->idx < low_idx)
		{
			low_idx = stack_a->idx;
			low_idx_pos = stack_a->cur_pos;
		}
		if (node_b->idx < stack_a->idx && \
				(!target_node || target_node->idx > stack_a->idx))
			target_node = stack_a;
		stack_a = stack_a->next;
	}
	if (!target_node)
		return (low_idx_pos);
	return (target_node->cur_pos);
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

static void	ps_get_own_cost(t_idxlst *stack)
{
	int	stack_len;

	stack_len = ps_lst_size(stack);
	while (stack)
	{
		if (stack->cur_pos <= stack_len / 2)
			stack->cost = stack->cur_pos;
		else
			stack->cost = -(stack_len - stack->cur_pos);
		stack = stack->next;
	}
}

void	ps_update_cost(t_idxlst *stack_a, t_idxlst *stack_b)
{
	t_idxlst	*aux_node;

	ps_get_own_cost(stack_a);
	ps_get_own_cost(stack_b);
	while (stack_b)
	{
		aux_node = stack_a;
		while (aux_node->cur_pos != stack_b->target_pos)
			aux_node = aux_node->next;
		if (stack_b->cost * aux_node->cost >= 0)
		{
			if (ft_abs(stack_b->cost) < ft_abs(aux_node->cost))
				stack_b->cost = aux_node->cost;
		}
		else
			stack_b->cost -= aux_node->cost;
		stack_b = stack_b->next;
	}
}
