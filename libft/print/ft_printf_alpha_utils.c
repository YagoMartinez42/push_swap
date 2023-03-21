/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_alpha_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:25:08 by samartin          #+#    #+#             */
/*   Updated: 2022/11/25 14:32:45 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	pf_putchar(int chr)
{
	unsigned int	done;

	done = write (1, &chr, 1);
	return (done);
}

unsigned int	pf_putstr(char *str)
{
	unsigned int	count;

	count = 0;
	if (str)
	{
		while (*str)
		{
			count += write (1, str, 1);
			str++;
		}
	}
	else
	{
		write(1, "(null)", 6);
		count = 6;
	}
	return (count);
}
