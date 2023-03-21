/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:37:06 by samartin          #+#    #+#             */
/*   Updated: 2022/11/25 14:35:15 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	pf_puthex(unsigned long num, char *hex_symbols)
{
	int				dig;
	unsigned int	count;
	char			nb_digits [16];

	dig = 0;
	while (num >= 16)
	{
		nb_digits[dig] = hex_symbols[(num % 16)];
		num = num / 16;
		dig++;
	}
	nb_digits[dig] = hex_symbols[num];
	count = (unsigned int)(dig + 1);
	while (dig >= 0)
	{
		write (1, (nb_digits + dig), 1);
		dig--;
	}
	return (count);
}

unsigned int	pf_putaddr(void *addr)
{
	unsigned int	count;

	count = write (1, "0x", 2);
	count += pf_puthex((unsigned long)addr, "0123456789abcdef");
	return (count);
}
