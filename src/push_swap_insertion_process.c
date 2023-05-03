/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_insertion_process.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:14:39 by samartin          #+#    #+#             */
/*   Updated: 2023/05/03 12:44:14 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_update_chosen(t_idxlst *node)
{
	int	move;

	if (node->cost < 0 && node->target_pos && node->cur_pos)
		move = -3;
	else if (node->cost < 0 && node->target_pos && !(node->cur_pos))
		move = -2;
	else if (node->cost < 0 && !(node->target_pos) && node->cur_pos)
		move = -1;
	else if (node->cost > 0 && node->target_pos && node->cur_pos)
		move = 3;
	else if (node->cost > 0 && node->target_pos && !(node->cur_pos))
		move = 2;
	else if (node->cost > 0 && !(node->target_pos) && node->cur_pos)
		move = 1;
	else
		move = 0;
	return (move);
}

static void	ps_do_move(t_idxlst **stack_a, t_idxlst **stack_b, int move)
{
	if (move == 0)
		ps_pa(stack_a, stack_b);
	else if (move == 1)
		ps_rb(stack_b);
	else if (move == 2)
		ps_ra(stack_a);
	else if (move == 3)
		ps_rr(stack_a, stack_b);
	else if (move == -1)
		ps_rrb(stack_b);
	else if (move == -2)
		ps_rra(stack_a);
	else if (move == -3)
		ps_rrr(stack_a, stack_b);
}

void	ps_move_less_cost(t_idxlst **stack_a, t_idxlst **stack_b)
{
	unsigned int	next_cost;
	int				move;
	t_idxlst		*node;

	node = *stack_b;
	next_cost = ft_abs(node->cost);
	move = ps_update_chosen(node);
	while (node && next_cost)
	{
		if (ft_abs(node->cost) < next_cost)
			move = ps_update_chosen(node);
		node = node->next;
	}
	ps_do_move(stack_a, stack_b, move);
}
