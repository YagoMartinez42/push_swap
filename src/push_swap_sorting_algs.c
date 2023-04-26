/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting_algs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:08:13 by samartin          #+#    #+#             */
/*   Updated: 2023/04/25 16:34:33 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_dump_to_b(t_idxlst **stack_a, t_idxlst **stack_b)
{
	int	stack_size;
	int	pushes;
	int	i;

	stack_size = ps_lst_size(*stack_a);
	pushes = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushes < stack_size / 2)
	{
		if ((*stack_a)->idx <= stack_size / 2)
		{
			ps_pb(stack_a, stack_b);
			pushes++;
		}
		else
			ps_ra(stack_a);
		i++;
	}
	while (stack_size - pushes > 3)
	{
		ps_pb(stack_a, stack_b);
		pushes++;
	}
}

void	ps_rotative_insertion(t_idxlst **stack_a)
{
	t_idxlst	*stack_b;

	stack_b = NULL;
	ps_dump_to_b(stack_a, &stack_b);
}