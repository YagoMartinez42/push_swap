/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:11:18 by samartin          #+#    #+#             */
/*   Updated: 2023/05/10 14:49:44 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * It prints an error message and exits the program. Subject states that giving
 * no parameters (asigned code 101) should show no message. Same goes if the
 * provided list was already sorted (code 105).
 * 
 * @param code The error code.
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 */
void	error_exit(int code, t_idxlst *stack_a, t_idxlst *stack_b)
{
	if (code == 101)
		code = 101;
	else if (code == 102)
		ft_putstr_fd("Error\nInvalid list\n", 2);
	else if (code == 103)
		ft_putstr_fd("Error\nDuplicated values in list\n", 2);
	else if (code == 104)
		ft_putstr_fd("Error\nNumbers out of range of INT\n", 2);
	else if (code == 105)
		code = 0;
	else if (code == 106)
		ft_putstr_fd("Error\nUnknown instruction\n", 2);
	else
		ft_putstr_fd("Error\n(Untracked error)\n", 2);
	if (stack_a)
		stack_a = ps_lst_clear(stack_a);
	if (stack_b)
		stack_b = ps_lst_clear(stack_b);
	exit(code);
}
