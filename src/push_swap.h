/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:17:59 by samartin          #+#    #+#             */
/*   Updated: 2023/04/25 16:33:43 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_idxlst
{
	long			value;
	int				idx;
	int				cur_pos;
	int				target_pos;
	int				cost_up;
	int				cost_rev;
	struct s_idxlst	*next;
}	t_idxlst;

void		ps_lst_add_back(t_idxlst **lst, t_idxlst *newnode);
t_idxlst	*ps_lst_clear(t_idxlst *lst);
t_idxlst	*ps_lst_new(long value);
int			ps_lst_size(t_idxlst *lst);
t_idxlst	*parse_args(size_t argc, char **argv);
int			*ps_atoi(char **str, int *nbp);
void		ws_to_space(char *str);
void		check_dupes(t_idxlst *lst);
void		check_int_sized(t_idxlst *lst);
void		index_stack(t_idxlst **stack);
void		error_exit(int code, t_idxlst *stack_a, t_idxlst *stack_b);
void		ps_swap(t_idxlst **top);
void		ps_push(t_idxlst **stack_o, t_idxlst **stack_d);
void		ps_rotate(t_idxlst **stack);
void		ps_rev_rotate(t_idxlst **stack);
void		ps_sa(t_idxlst **stack_a);
void		ps_sb(t_idxlst **stack_b);
void		ps_ss(t_idxlst **stack_a, t_idxlst **stack_b);
void		ps_pa(t_idxlst **stack_a, t_idxlst **stack_b);
void		ps_pb(t_idxlst **stack_a, t_idxlst **stack_b);
void		ps_ra(t_idxlst **stack_a);
void		ps_rb(t_idxlst **stack_b);
void		ps_rr(t_idxlst **stack_a, t_idxlst **stack_b);
void		ps_rra(t_idxlst **stack_a);
void		ps_rrb(t_idxlst **stack_b);
void		ps_rrr(t_idxlst **stack_a, t_idxlst **stack_b);
int			is_sorted(t_idxlst *lst);
void		ps_sort_3(t_idxlst **stack_a);
void		ps_sort_5(t_idxlst **stack_a);

void	print_stacks(t_idxlst *stack_a, t_idxlst *stack_b);  // TEST ONLY!!!
#endif