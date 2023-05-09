/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_insertion_process.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:14:39 by samartin          #+#    #+#             */
/*   Updated: 2023/05/09 11:40:19 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_double(t_idxlst **stack_a, t_idxlst **stack_b, t_idxlst *node)
{
	int	dir;

	if (node->target_pos > ps_lst_size(*stack_a) / 2)
		dir = -1;
	else
		dir = 1;
	if (node->cost > 0 && dir == 1)
		ps_rr(stack_a, stack_b);
	else if (node->cost < 0 && dir == -1)
		ps_rrr(stack_a, stack_b);
	else if (node->cost > 0)
	{
		ps_rra(stack_a);
		ps_rb(stack_b);
	}
	else
	{
		ps_ra(stack_a);
		ps_rrb(stack_b);
	}
}

static void	ps_do_move(t_idxlst **stack_a, t_idxlst **stack_b, t_idxlst *node)
{
	if (node->target_pos && node->cur_pos)
		ps_double(stack_a, stack_b, node);
	else if (node->cost > 0 && node->target_pos && !(node->cur_pos))
		ps_ra(stack_a);
	else if (node->cost > 0 && !(node->target_pos) && node->cur_pos)
		ps_rb(stack_b);
	else if (node->cost < 0 && node->target_pos && !(node->cur_pos))
		ps_rra(stack_a);
	else if (node->cost < 0 && !(node->target_pos) && node->cur_pos)
		ps_rrb(stack_b);
	else
		ps_pa(stack_a, stack_b);
}

void	ps_move_less_cost(t_idxlst **stack_a, t_idxlst **stack_b)
{
	unsigned int	next_cost;
	t_idxlst		*node;
	t_idxlst		*chosen;

	node = *stack_b;
	next_cost = ft_abs(node->cost);
	chosen = node;
	while (node && next_cost)
	{
		if (ft_abs(node->cost) < next_cost)
		{
			chosen = node;
			next_cost = ft_abs(node->cost);
		}
		node = node->next;
	}
	ps_do_move(stack_a, stack_b, chosen);
}
