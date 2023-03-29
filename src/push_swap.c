/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:17:41 by samartin          #+#    #+#             */
/*   Updated: 2023/03/29 16:43:05 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_swap_command_list_generation(t_bllist *lst)
{
	lst++;
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
	//ps_out = push_swap_command_list_generation(lst);
	//ft_printf("%s", ps_out);
	ft_bllst_clear(lst);
	return (1);
}
