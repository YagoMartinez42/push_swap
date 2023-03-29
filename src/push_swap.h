/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:17:59 by samartin          #+#    #+#             */
/*   Updated: 2023/03/29 16:38:50 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

t_bllist	*parse_args(size_t argc, char **argv);
void		check_dupes(t_bllist *lst);
void		error_exit(int code, t_bllist *stack_a, t_bllist *stack_b);

#endif