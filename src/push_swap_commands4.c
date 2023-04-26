/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:44:21 by samartin          #+#    #+#             */
/*   Updated: 2023/04/25 13:56:11 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rra(t_idxlst **stack_a)
{
	ps_rev_rotate(stack_a);
	ft_printf("ra\n");
}

void	ps_rrb(t_idxlst **stack_b)
{
	ps_rev_rotate(stack_b);
	ft_printf("rb\n");
}

void	ps_rrr(t_idxlst **stack_a, t_idxlst **stack_b)
{
	ps_rev_rotate(stack_a);
	ps_rev_rotate(stack_b);
	ft_printf("rr\n");
}
