/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:17:41 by samartin          #+#    #+#             */
/*   Updated: 2023/04/11 16:01:05 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b) // TEST ONLY!!!
{
	while (stack_a)
	{
		if (stack_a)
		{
			ft_printf("%i | %i ", ((t_idxd_node *)stack_a->content)->value, ((t_idxd_node *)stack_a->content)->idx);
			stack_a = stack_a->next;
		}
		if (stack_b)
		{
			ft_printf("B: %i | %i", ((t_idxd_node *)stack_b->content)->value, ((t_idxd_node *)stack_b->content)->idx);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	index_stack(t_list **stack)
{
	t_list	*node;
	t_list	*n2idx;
	size_t	stack_len;
	size_t	i;
	int		min;

	stack_len = 0;
	node = *stack;
	while (node)
	{
		node = node->next;
		stack_len++;
	}
	i = 0;
	while (i < stack_len)
	{
		min = __INT_MAX__;
		node = *stack;
		while (node)
		{
			if (((t_idxd_node *)node->content)->idx == -1 && \
					((t_idxd_node *)node->content)->value < min)
			{
				n2idx = node;
				min = ((t_idxd_node *)node->content)->value;
			}
			node = node->next;
		}
		((t_idxd_node *)node->content)->idx = i;
		i++;
	}
}

void	push_swap_command_list_generation(t_list *stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (is_sorted(stack_a))
		error_exit(105, stack_a, NULL);
	//index
	index_stack(&stack_a);
	print_stacks(stack_a, stack_b);
	//algorithm
	//printf command
	//is_sorted(stack_a) && !stack_b : break;
}

void	check_leaks(void)
{
	system("leaks -q push_swap"); // destroy me.
}

int	main(int argc, char **argv)
{
	t_list	*lst;

	atexit(check_leaks); // ding ! ding !
	lst = NULL;
	if (argc < 2)
		error_exit(101, NULL, NULL);
	lst = parse_args(argc - 1, argv);
	check_dupes(lst);
	check_int_sized(lst);
	push_swap_command_list_generation(lst);
	ft_lstclear(&lst, del_idxnode);
	return (0);
}
