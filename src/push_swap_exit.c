/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:11:18 by samartin          #+#    #+#             */
/*   Updated: 2023/04/11 15:42:08 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_idxnode(void *content)
{
	free(content);
}

/**
 * It prints an error message and exits the program. Subject states that giving
 * no parameters (asigned code 101) should show no message. Same goes if the
 * provided list was already sorted (code 105).
 * 
 * @param code The error code.
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 */
void	error_exit(int code, t_list *stack_a, t_list *stack_b)
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
		code = 105;
	else
		ft_putstr_fd("Error\n(Untracked error)\n", 2);
	if (stack_a)
		ft_lstclear(&stack_a, del_idxnode);
	if (stack_b)
		ft_lstclear(&stack_b, del_idxnode);
	exit(code);
}
