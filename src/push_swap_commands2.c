/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:29:37 by samartin          #+#    #+#             */
/*   Updated: 2023/04/25 13:44:47 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("sa\n");
	ps_swap(stack_b);
	ft_printf("sb\n");
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
