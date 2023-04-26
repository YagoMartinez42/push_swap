/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:14:33 by samartin          #+#    #+#             */
/*   Updated: 2023/04/20 15:41:56 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_idxlst **top)
{
	t_idxlst	*subtop;

	if (top && (*top)->next)
	{
		subtop = (*top)->next;
		(*top)->next = subtop->next;
		subtop->next = *top;
		*top = subtop;
	}
}

void	ps_push(t_idxlst **stack_o, t_idxlst **stack_d)
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
