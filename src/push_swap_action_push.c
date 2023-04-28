/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:14:33 by samartin          #+#    #+#             */
/*   Updated: 2023/04/26 13:19:38 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_push(t_idxlst **stack_o, t_idxlst **stack_d)
{
	t_idxlst	*node;

	if (stack_d && stack_o && *stack_o)
	{
		node = *stack_o;
		*stack_o = (*stack_o)->next;
		node->next = *stack_d;
		*stack_d = node;
	}
}

void	ps_pa(t_idxlst **stack_a, t_idxlst **stack_b)
{
	ps_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	ps_pb(t_idxlst **stack_a, t_idxlst **stack_b)
{
	ps_push(stack_a, stack_b);
	ft_printf("pb\n");
}
