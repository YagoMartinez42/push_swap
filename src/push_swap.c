/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:17:41 by samartin          #+#    #+#             */
/*   Updated: 2023/04/28 16:26:46 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_idxlst *stack_a, t_idxlst *stack_b) // TEST ONLY!!!
{
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("v%i | i%i | p%i | t%i", stack_a->value, stack_a->idx, stack_a->cur_pos, stack_a->target_pos);
			stack_a = stack_a->next;
		}
		if (stack_b)
		{
			ft_printf("  B: v%i | i%i | p%i | t%i", stack_b->value, stack_b->idx, stack_b->cur_pos, stack_b->target_pos);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}

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
	print_stacks(stack_a, NULL);	
	return (stack_a);
}

void	check_leaks(void)
{
	system("leaks -q push_swap"); // destroy me.
}

int	main(int argc, char **argv)
{
	t_idxlst	*lst;

	atexit(check_leaks); // ding ! ding !
	lst = NULL;
	if (argc < 2)
		error_exit(101, NULL, NULL);
	lst = parse_args(argc - 1, argv);
	check_dupes(lst);
	check_int_sized(lst);
	lst = push_swap_command_list_generation(lst);
	lst = ps_lst_clear(lst);
	return (0);
}
