/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:14:18 by samartin          #+#    #+#             */
/*   Updated: 2023/05/10 14:55:42 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ck_do_move(t_idxlst **stack_a, t_idxlst **stack_b, char *move)
{
	if (!(ft_strncmp(move, "pa\n", 3)))
		ps_pa(stack_a, stack_b);
	else if (!(ft_strncmp(move, "pb\n", 3)))
		ps_pb(stack_a, stack_b);
	else if (!(ft_strncmp(move, "sa\n", 3)))
		ps_sa(stack_a);
	else if (!(ft_strncmp(move, "sb\n", 3)))
		ps_sb(stack_a);
	else if (!(ft_strncmp(move, "ss\n", 3)))
		ps_ss(stack_a, stack_b);
	else if (!(ft_strncmp(move, "ra\n", 3)))
		ps_ra(stack_a);
	else if (!(ft_strncmp(move, "rb\n", 3)))
		ps_rb(stack_a);
	else if (!(ft_strncmp(move, "rr\n", 3)))
		ps_rr(stack_a, stack_b);
	else if (!(ft_strncmp(move, "rra\n", 4)))
		ps_rra(stack_a);
	else if (!(ft_strncmp(move, "rrb\n", 4)))
		ps_rrb(stack_b);
	else if (!(ft_strncmp(move, "rrr\n", 4)))
		ps_rrr(stack_a, stack_b);
	else
		error_exit(106, *stack_a, *stack_b);
}

static void	ck_veredict(t_idxlst *stack_a, t_idxlst	*stack_b)
{
	if (!stack_b && is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (stack_a)
		stack_a = ps_lst_clear(stack_a);
	if (stack_b)
		stack_b = ps_lst_clear(stack_b);
}

int	main(int argc, char **argv)
{
	t_idxlst	*stack_a;
	t_idxlst	*stack_b;
	char		*move;

	if (argc < 2)
		error_exit(101, NULL, NULL);
	stack_a = parse_args(argc - 1, argv);
	check_dupes(stack_a);
	check_int_sized(stack_a);
	move = get_next_line(0);
	stack_b = NULL;
	while (move && ft_strncmp(move, "\n", 1))
	{
		ck_do_move(&stack_a, &stack_b, move);
		free(move);
		move = get_next_line(0);
	}
	free (move);
	ck_veredict(stack_a, stack_b);
	return (0);
}
