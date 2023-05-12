/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:17:41 by samartin          #+#    #+#             */
/*   Updated: 2023/05/11 16:06:25 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_idxlst	*push_swap_command_list_generation(t_idxlst *stack_a)
{
	if (is_sorted(stack_a))
		error_exit(105, stack_a, NULL);
	if (ps_lst_size(stack_a) < 4)
		ps_sort_3(&stack_a);
	else if (ps_lst_size(stack_a) < 6)
	{
		index_stack(&stack_a);
		ps_sort_5(&stack_a);
	}
	else
	{
		index_stack(&stack_a);
		ps_rotative_insertion(&stack_a);
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_idxlst	*lst;

	lst = NULL;
	if (argc < 2)
		error_exit(101, NULL, NULL);
	lst = parse_args(argc - 1, argv);
	if (!lst)
		error_exit(102, NULL, NULL);
	check_dupes(lst);
	check_int_sized(lst);
	lst = push_swap_command_list_generation(lst);
	lst = ps_lst_clear(lst);
	return (0);
}
