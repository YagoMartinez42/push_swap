/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:17:59 by samartin          #+#    #+#             */
/*   Updated: 2023/04/03 18:04:17 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

t_bllist	*parse_args(size_t argc, char **argv);
void		check_dupes(t_bllist *lst);
void		check_int_sized(t_bllist *lst);
void		error_exit(int code, t_bllist *stack_a, t_bllist *stack_b);
void		swap(t_bllist **top);
void		push(t_bllist **stack_u, t_bllist **stack_d);
void		rotate(t_bllist **stack);
void		rev_rotate(t_bllist **stack);
int			is_sorted(t_bllist *lst);

#endif