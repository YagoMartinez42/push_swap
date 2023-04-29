/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting_algs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:08:13 by samartin          #+#    #+#             */
/*   Updated: 2023/04/29 16:08:03 by samartin         ###   ########.fr       */
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
	int	init_stack_sz;
	int	stack_sz;

	init_stack_sz = ps_lst_size(*stack_a);
	stack_sz = init_stack_sz;
	while (stack_sz > 3)
	{
		if (stack_sz < (init_stack_sz / 2) + 3 || (*stack_a)->idx < (stack_sz / 2))
		{
			ps_pb(stack_a, stack_b);
			stack_sz--;
		}
		else
			ps_ra(stack_a);
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
		print_stacks(*stack_a, stack_b);
	ps_dump_to_b(stack_a, &stack_b);
		print_stacks(*stack_a, stack_b);
	ps_sort_3(stack_a);
	while (stack_b)
	{
		ps_update_pos_idxs(*stack_a, stack_b);
		ps_update_cost(*stack_a, stack_b);
		//ps_move_less_cost(stack_a, &stack_b);
	}
	/*if (!is_sorted(*stack_a))
		ps_final_rotation(stack_a);*/
}
