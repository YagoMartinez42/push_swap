/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:11:18 by samartin          #+#    #+#             */
/*   Updated: 2023/03/30 14:21:48 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(int code, t_bllist *stack_a, t_bllist *stack_b)
{
	if (code == 101)
		code = 101;
	else if (code == 102)
	{
		ft_putstr_fd("Error\nInvalid list\n", 2);
		ft_bllst_clear(stack_a);
	}
	else if (code == 103)
	{
		ft_putstr_fd("Error\nDuplicated values in list\n", 2);
		ft_bllst_clear(stack_a);
	}
	else if (code == 104)
	{
		ft_putstr_fd("Error\nNumbers out of range of INT\n", 2);
		ft_bllst_clear(stack_a);
	}	
	else
	{
		ft_putstr_fd("Error\n(Untracked error)\n", 2);
		if (stack_a)
			ft_bllst_clear(stack_a);
		if (stack_b)
			ft_bllst_clear(stack_b);
	}
	exit(code);
}
