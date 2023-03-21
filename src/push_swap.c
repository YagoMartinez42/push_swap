/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:17:41 by samartin          #+#    #+#             */
/*   Updated: 2023/03/21 16:21:55 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char** argv)
{
	char	*ps_out;
	
	ps_out = push_swap_command_list_generation();
	ft_printf("%s", ps_out);
	return(1);
}