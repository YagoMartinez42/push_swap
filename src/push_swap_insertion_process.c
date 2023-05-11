/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_insertion_process.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:14:39 by samartin          #+#    #+#             */
/*   Updated: 2023/05/11 13:39:10 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * If neither of the node to be pushed and its target are at the top of their
 * stacks, both stacks are to be rotated, if both go in the same direction,
 * a double action like RR or RRR can be used.
 * 
 * @param stack_a A pointer to a pointer to a linked list representing the
 * current state of stack A (target at this point).
 * @param stack_b A pointer to a pointer to a linked list representing the
 * current state of stack B (origin at this point).
 * @param node An specific node in stack B.
 */
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

/**
 * Performs an specific move on two stacks based on the current and target
 * positions of a node in stack B. The action needed is calculated depending on
 * the sign of the cost and if both stacks A and B are to be rotated or the
 * node or the target are already at the top of their stacks. Only if both are,
 * the node is ready to be pushed into its sorted position in A.
 * 
 * @param stack_a A pointer to a pointer to a linked list representing the
 * current state of stack A (target at this point).
 * @param stack_b A pointer to a pointer to a linked list representing the
 * current state of stack B (origin at this point).
 * @param node An specific node in stack B, it was the chosen one with less
 * cost of all in the stack.
 */
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

/**
 * The function selects the node with the lowest cost from stack B and calls
 * ps_do_move to calculate and execute the next action to move that node to
 * the A stack.
 * 
 * @param stack_a A pointer to a pointer to a linked list representing the
 * current state of stack A (target at this point).
 * @param stack_b A pointer to a pointer to a linked list representing the
 * current state of stack B (origin at this point).
 */
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
