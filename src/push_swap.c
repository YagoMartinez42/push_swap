/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:17:41 by samartin          #+#    #+#             */
/*   Updated: 2023/04/03 18:10:20 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_bllist *stack_a, t_bllist *stack_b) // TEST ONLY!!!
{
	while (stack_a)
	{
		ft_printf("%i ", stack_a->content);
		if (stack_b)
			ft_printf("%i ", stack_b->content);
		stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
		ft_printf("\n");
	}
	ft_printf("\n");
}

char	*push_swap_command_list_generation(t_bllist *stack_a)
{
	t_bllist	*stack_b;

	if (is_sorted(stack_a))
		error_exit(105, stack_a, NULL);
	return ("");
}

void	check_leaks(void)
{
	system("leaks -q push_swap"); // destroy me.
}

int	main(int argc, char **argv)
{
	t_bllist	*lst;
	char		*ps_out;

	atexit(check_leaks); // ding ! ding !
	lst = NULL;
	ps_out = NULL;
	if (argc < 2)
		error_exit(101, NULL, NULL);
	lst = parse_args(argc - 1, argv);
	check_dupes(lst);
	check_int_sized(lst);
	ps_out = push_swap_command_list_generation(lst);
	//ft_printf("%s", ps_out);
	ft_bllst_clear(lst);
	return (0);
}
