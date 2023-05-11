/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_insertion_index_updates.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:30:28 by samartin          #+#    #+#             */
/*   Updated: 2023/05/11 11:45:04 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * The function updates the current position of each element in a linked list.
 * 
 * @param stack A pointer to a linked list representing a stack.
 */
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

/**
 * The function finds the position of the target node in a stack based on
 * between which index values of a sorted incomplete stack can fit the index of
 * the given node located in the other stack. It will instead be the lowest
 * index of all the stack in case there is no pair to fit between.
 * 
 * @param stack_a A pointer to a linked list representing stack A in a sorting
 * algorithm. A is already sorted at this point but still incomplete.
 * @param node_b The node we want to find a target position for in the stack A.
 * 
 * @return An integer value, which is either the current position of the node
 * with the lowest index in the stack_a list, or (preferently) the current
 * position of the node in the stack_a list that has the lowest index greater
 * than the index of the `node_b` parameter.
 */
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

/**
 * The function updates the current positions of all nodes in two stacks and
 * target positions for all stack_b nodes. This function is to be called after
 * every sorting action. Each node in the linked list contains a current own
 * position value and a target position value, which represents the position
 * that the node should be in after the sorting algorithm is complete.
 * 
 * @param stack_a A pointer to a linked list representing the target stack
 * (stack A) that needs to receive the stack B nodes to finaly be sorted.
 * @param stack_b A pointer to a linked list representing an auxiliar stack in
 * this sorting algorithm.
 */
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

/**
 * The function assigns a cost value to each element in a linked list based on
 * its position in the list. The cost takes a negative value if the shortest
 * way to the top is reverse rotation.
 * 
 * @param stack A pointer to a linked list representing a stack. Each node of
 * the linked list contains an integer value for current position "cur_pos" and
 * a value representing the cost to move it to the top of the stack, which is
 * updated in this function.
 */
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

/**
 * The function updates the cost of elements in two stacks based on their
 * positions and adds the cost of moving the target in A to the cost of moving
 * the node in B, but only if there are to be opositely moved or one cost is
 * 0, if they can be moved in the same direction with double action, the cost
 * will be only the higher of the two.
 * 
 * @param stack_a A pointer to a linked list representing stack A (target).
 * @param stack_b `A pointer to a linked list representing stack B (auxiliar).
 */
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
