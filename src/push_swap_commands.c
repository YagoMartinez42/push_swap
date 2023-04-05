/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:14:33 by samartin          #+#    #+#             */
/*   Updated: 2023/04/05 16:44:36 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **top)
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

void	push(t_list **stack_d, t_list **stack_i)
{
	t_list	*node;

	if (stack_i && stack_d && *stack_d)
	{
		node = *stack_d;
		*stack_d = (*stack_d)->next;
		node->next = *stack_i;
		*stack_i = node;
	}
}

void	rotate(t_list **stack)
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

void	rev_rotate(t_list **stack)
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
