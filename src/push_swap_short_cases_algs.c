/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_short_cases_algs.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:18:36 by samartin          #+#    #+#             */
/*   Updated: 2023/04/28 16:30:59 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_3(t_idxlst **stack_a)
{
	int	n[3];

	n[0] = (*stack_a)->value;
	n[1] = (*stack_a)->next->value;
	if ((*stack_a)->next->next)
		n[2] = (*stack_a)->next->next->value;
	if (ps_lst_size (*stack_a) == 2 || (n[2] > n[0] && n[0] > n[1]))
		ps_sa(stack_a);
	else if (n[0] > n[1] && n[1] > n[2])
	{
		ps_sa(stack_a);
		ps_rra(stack_a);
	}
	else if (n[0] > n[2] && n[2] > n[1])
		ps_ra(stack_a);
	else if (n[1] > n[2] && n[2] > n[0])
	{
		ps_sa(stack_a);
		ps_ra(stack_a);
	}
	else
		ps_rra(stack_a);
}

static void	ps_get_extr(t_idxlst **stack_a, t_idxlst **stack_b, int len)
{
	while ((*stack_a)->idx != 0 && (*stack_a)->idx != (len - 1))
		ps_ra(stack_a);
	ps_pb(stack_a, stack_b);
}

void	ps_sort_5(t_idxlst **stack_a)
{
	t_idxlst	*stack_b;
	int			len;

	stack_b = NULL;
	len = ps_lst_size(*stack_a);
	ps_get_extr(stack_a, &stack_b, len);
	if (len == 5)
		ps_get_extr(stack_a, &stack_b, len);
	if (!(is_sorted(*stack_a)))
		ps_sort_3(stack_a);
	ps_pa(stack_a, &stack_b);
	while (!(is_sorted(*stack_a)) || (stack_b))
	{
		if (!(is_sorted(*stack_a)))
			ps_ra(stack_a);
		if (stack_b)
			ps_pa(stack_a, &stack_b);
	}
}
