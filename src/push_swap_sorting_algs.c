/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting_algs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:08:13 by samartin          #+#    #+#             */
/*   Updated: 2023/05/09 11:53:41 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * The function ps_dump_to_b moves elements from stack A to stack B until there
 * are only three elements left in stack A. The elements with index belonging
 * to the second half of the sorted stack are skiped until the first half is
 * out.
 * 
 * @param stack_a The address of a pointer to the linked list stack A.
 * @param stack_b This stack is used to temporarily store elements during the
 * sorting process.
 */
static void	ps_dump_to_b(t_idxlst **stack_a, t_idxlst **stack_b)
{
	int	stack_sz;
	int	too_many_r;
	int	segment;

	stack_sz = ps_lst_size(*stack_a);
	too_many_r = 0;
	segment = stack_sz / 5;
	while (stack_sz > 3)
	{
		if ((*stack_a)->idx <= segment || too_many_r >= 6)
		{
			ps_pb(stack_a, stack_b);
			if (too_many_r >= 6 && (*stack_a)->idx > segment)
				ps_rb(stack_b);
			stack_sz--;
			segment++;
			too_many_r = 0;
		}
		else
		{
			too_many_r++;
			ps_ra(stack_a);
		}
	}
}

/**
 * Rotates a stack that is already back with all the initial nodes in a sorted
 * order but not with the lowest at top. Will take the shortest way with
 * either RA or RRA.
 * 
 * @param stack_a The address of a pointer to the linked list stack A.
 */
static void	ps_final_rotation(t_idxlst **stack_a)
{
	int	len;

	len = ps_lst_size(*stack_a);
	while (!is_sorted(*stack_a))
	{
		if ((*stack_a)->idx > len / 2)
			ps_ra(stack_a);
		else
			ps_rra(stack_a);
	}
}

/**
 * Performs a rotative insertion sort algorithm on a stack. The steps are:
 * Move all nodes but 3 to stack B, those 3 left are from the highest half.
 * Sort the 3 remaining in A.
 * Go moving back the nodes to A with the less cost moves while updating their
 * costs and positions.
 * When all are back in A, rotate or reverse until the first index is at top.
 * 
 * @param stack_a The address of a pointer to the linked list stack A.
 */
void	ps_rotative_insertion(t_idxlst **stack_a)
{
	t_idxlst	*stack_b;

	stack_b = NULL;
	ps_dump_to_b(stack_a, &stack_b);
	ps_sort_3(stack_a);
	while (stack_b)
	{
		ps_update_pos_idxs(*stack_a, stack_b);
		ps_update_cost(*stack_a, stack_b);
		ps_move_less_cost(stack_a, &stack_b);
	}
	if (!is_sorted(*stack_a))
		ps_final_rotation(stack_a);
}
