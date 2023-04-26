/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:44:17 by samartin          #+#    #+#             */
/*   Updated: 2023/04/25 13:56:07 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
