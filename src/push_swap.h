/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:17:59 by samartin          #+#    #+#             */
/*   Updated: 2023/04/05 12:59:16 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_idxd_node
{
	int				value;
	unsigned int	idx;
}	t_idxd_node;

t_list	*parse_args(size_t argc, char **argv);
int		*ps_atoi(char **str, int *nbp);
void	ws_to_space(char *str);
void	check_dupes(t_list *lst);
void	check_int_sized(t_list *lst);
void	error_exit(int code, t_list *stack_a, t_list *stack_b);
void	swap(t_list **top);
void	push(t_list **stack_u, t_list **stack_d);
void	rotate(t_list **stack);
void	rev_rotate(t_list **stack);
int		is_sorted(t_list *lst);

#endif