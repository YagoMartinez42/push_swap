/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:44:17 by samartin          #+#    #+#             */
/*   Updated: 2023/05/10 14:49:30 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_rotate(t_idxlst **stack)
{
	t_idxlst	*node;

	if (stack && *stack && (*stack)->next)
	{
		node = *stack;
		*stack = (*stack)->next;
		node->next = NULL;
		ps_lst_add_back(stack, node);
	}
}

void	ps_ra(t_idxlst **stack_a)
{
	ps_rotate(stack_a);
	ft_printf("ra\n");
}

void	ps_rb(t_idxlst **stack_b)
{
	ps_rotate(stack_b);
	ft_printf("rb\n");
}

void	ps_rr(t_idxlst **stack_a, t_idxlst **stack_b)
{
	ps_rotate(stack_a);
	ps_rotate(stack_b);
	ft_printf("rr\n");
}
