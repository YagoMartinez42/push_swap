/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting_algs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:08:13 by samartin          #+#    #+#             */
/*   Updated: 2023/04/17 16:07:13 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int bb_do_rotation(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b && (*stack_b)->next && ((t_idxd_node *)(*stack_b)->content)->value < ((t_idxd_node *)(*stack_b)->content)->value)
	{
		ft_printf("rr\n");
		ps_rotate(stack_b);
	}
	else
		ft_printf("ra\n");
	ps_rotate(stack_a);
	return (1);
}

int bb_do_rev_rotation(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b && (*stack_b)->next && ((t_idxd_node *)(*stack_b)->content)->value > ((t_idxd_node *)(*stack_b)->content)->value)
	{
		ft_printf("rrr\n");
		ps_rev_rotate(stack_b);
	}
	else
		ft_printf("rra\n");
	ps_rev_rotate(stack_a);
	return (1);
}

int bb_do_swap(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b && (*stack_b)->next && ((t_idxd_node *)(*stack_b)->content)->value < ((t_idxd_node *)(*stack_b)->content)->value)
	{
		ft_printf("ss\n");
		ps_swap(stack_b);
	}
	else
		ft_printf("sa\n");
	ps_swap(stack_a);
	return (1);
}

void bb_goto_zero (t_list **stack_a, t_list **stack_b, size_t len)
{
	if (((t_idxd_node *)(*stack_b)->content)->idx < (int)(len / 2))
	{
		while (((t_idxd_node *)(*stack_b)->content)->idx)
			bb_do_rev_rotation(stack_a, stack_b);
	}
	else
	{
		while (((t_idxd_node *)(*stack_b)->content)->idx)
			bb_do_rotation(stack_a, stack_b);		
	}
}

int	not_a_bubble_sort(t_list **stack_a, t_list **stack_b, int i, size_t *len)
{
	static int endpoint = -1;

	if (endpoint == -1)
		endpoint = (int)*len;
	if (*stack_b && *stack_a)
	{
		if (((t_idxd_node *)(*stack_b)->content)->idx == ((t_idxd_node *)(*stack_a)->next->content)->idx - 1)
		{
			ft_printf("pa\n");
			ps_push(stack_b, stack_a);
			if (!is_sorted(*stack_a))
				i += bb_do_rotation(stack_b, stack_a);
		}
	}
	if (*stack_a && (*stack_a)->next)
	{
		if (((t_idxd_node *)(*stack_a)->content)->idx > ((t_idxd_node *)(*stack_a)->next->content)->idx)
		{
			if (((t_idxd_node *)(*stack_a)->content)->idx == (int)(len - 1))
				i += bb_do_rotation(stack_a, stack_b);
			if (ft_abs(((t_idxd_node *)(*stack_a)->content)->idx - i) > *len / 5)
			{
				ft_printf("pb\n");
				ps_push(stack_a, stack_b);
			}
			else
				bb_do_swap(stack_a, stack_b);
		}
		else
			i += bb_do_rotation(stack_a, stack_b);
		if (i >= endpoint)
		{
			bb_goto_zero(stack_a, stack_b, *len);
			endpoint--;
		}
	}
	return(i);
}