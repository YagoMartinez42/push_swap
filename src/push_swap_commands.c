/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:14:33 by samartin          #+#    #+#             */
/*   Updated: 2023/04/14 12:41:11 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_list **top)
{
	t_list	*subtop;

	if (top && (*top)->next)
	{
		subtop = (*top)->next;
		(*top)->next = subtop->next;
		subtop->next = *top;
		*top = subtop;
	}
}

void	ps_push(t_list **stack_o, t_list **stack_d)
{
	t_list	*node;

	if (stack_d && stack_o && *stack_o)
	{
		node = *stack_o;
		*stack_o = (*stack_o)->next;
		node->next = *stack_d;
		*stack_d = node;
	}
}

void	ps_rotate(t_list **stack)
{
	t_list	*node;

	if (stack && *stack && (*stack)->next)
	{
		node = *stack;
		*stack = (*stack)->next;
		node->next = NULL;
		ft_lstadd_back(stack, node);
	}
}

void	ps_rev_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*prev;

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
