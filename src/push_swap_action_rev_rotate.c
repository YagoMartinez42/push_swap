/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action_rev_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:44:21 by samartin          #+#    #+#             */
/*   Updated: 2023/04/26 13:26:57 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rev_rotate(t_idxlst **stack)
{
	t_idxlst	*last;
	t_idxlst	*prev;

	if (stack && *stack && (*stack)->next)
	{
		last = *stack;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	ps_rra(t_idxlst **stack_a)
{
	ps_rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	ps_rrb(t_idxlst **stack_b)
{
	ps_rev_rotate(stack_b);
	ft_printf("rrb\n");
}

void	ps_rrr(t_idxlst **stack_a, t_idxlst **stack_b)
{
	ps_rev_rotate(stack_a);
	ps_rev_rotate(stack_b);
	ft_printf("rrr\n");
}
