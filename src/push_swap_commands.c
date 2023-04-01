/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:14:33 by samartin          #+#    #+#             */
/*   Updated: 2023/04/01 17:14:12 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_bllist **top)
{
	t_bllist	*subtop;

	if (top)
	{
		subtop = (*top)->next;
    	if (*top && subtop)
    	{
	        (*top)->next = subtop->next;
            subtop->next->prev = *top;
			subtop->prev = NULL;
			subtop->next = *top;
        	(*top)->prev = subtop;
			*top = subtop;
		}
    }
}

void	push(t_bllist **stack_d, t_bllist **stack_i)
{
	t_bllist	*node;
	
	if (stack_i && stack_d && *stack_d)
	{
		node = *stack_d;
		if (node->next)
			node->next->prev = NULL;
		*stack_d = node->next;
		if (*stack_i)
			(*stack_i)->prev = node;
		node->next = *stack_i;
		*stack_i = node;
	}
}

void	rotate(t_bllist **stack)
{
	t_bllist	*last;

	if (stack && *stack)
		last = ft_bllst_last(*stack);
	else
		return ;
	if (last && last != *stack)
	{
		(*stack)->prev = last;
		last->next = *stack;
		(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		last->next->next = NULL;
	}
}

void	rev_rotate(t_bllist **stack)
{
	t_bllist	*last;

	if (stack && *stack)
		last = ft_bllst_last(*stack);
	else
		return ;
	if (last && last != *stack)
	{
		last->next = *stack;
		(*stack)->prev = last;
		last->prev->next = NULL;
		*stack = last;
		last->prev = NULL;
	}
}
