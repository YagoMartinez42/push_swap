/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_short_cases_algs.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:18:36 by samartin          #+#    #+#             */
/*   Updated: 2023/04/25 16:35:36 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_3(t_idxlst **stack_a)
{
	if (ps_lst_size (*stack_a) == 2 || ((*stack_a)->value > \
			(*stack_a)->next->value && (*stack_a)->value < \
			(*stack_a)->next->next->value))
		ps_sa(stack_a);
	else if ((*stack_a)->value > (*stack_a)->next->value && \
			(*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		ps_sa(stack_a);
		ps_ra(stack_a);
	}
	else if ((*stack_a)->value > (*stack_a)->next->value && \
			(*stack_a)->next->value < (*stack_a)->next->next->value)
		ps_ra(stack_a);
	else if ((*stack_a)->value < (*stack_a)->next->next->value && \
			(*stack_a)->next->value > (*stack_a)->next->next->value)
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
	{
		ps_rotate(stack_a);
		ft_printf("ra\n");
	}
	ps_push(stack_a, stack_b);
	ft_printf("pb\n");
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
	ps_push(&stack_b, stack_a);
	ft_printf("pa\n");
	while (!(is_sorted(*stack_a)) || (stack_b))
	{
		if (!(is_sorted(*stack_a)))
		{
			ps_rotate(stack_a);
			ft_printf("ra\n");
		}
		if (stack_b)
		{
			ps_push(&stack_b, stack_a);
			ft_printf("pa\n");
		}
	}
}
