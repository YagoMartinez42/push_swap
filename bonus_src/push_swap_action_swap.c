/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action_swap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:29:37 by samartin          #+#    #+#             */
/*   Updated: 2023/05/15 16:48:47 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_swap(t_idxlst **top)
{
	t_idxlst	*subtop;

	if (top && *top && (*top)->next)
	{
		subtop = (*top)->next;
		(*top)->next = subtop->next;
		subtop->next = *top;
		*top = subtop;
	}
}

void	ps_sa(t_idxlst **stack_a)
{
	ps_swap(stack_a);
	ft_printf("sa\n");
}

void	ps_sb(t_idxlst **stack_b)
{
	ps_swap(stack_b);
	ft_printf("sb\n");
}

void	ps_ss(t_idxlst **stack_a, t_idxlst **stack_b)
{
	ps_swap(stack_a);
	ps_swap(stack_b);
	ft_printf("ss\n");
}
