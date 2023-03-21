/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:25:17 by samartin          #+#    #+#             */
/*   Updated: 2022/12/06 13:11:36 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static unsigned int	drop_nb(char *nbdigs, unsigned int n)
{
	int	dig;

	dig = 0;
	while (n >= 10)
	{
		nbdigs[dig] = (n % 10) + '0';
		n = n / 10;
		dig++;
	}
	nbdigs[dig] = n + '0';
	return (dig);
}

static unsigned int	manage_neg(int num, unsigned int *count)
{
	if (num == -2147483648)
	{
		write (1, "-2", 2);
		num = 147483648;
		*count = 2;
	}
	if (num < 0)
	{
		write (1, "-", 1);
		num = num * -1;
		*count = 1;
	}
	return (num);
}

unsigned int	pf_putint(int num, char mode)
{
	int				dig;
	unsigned int	count;
	char			nb_digits [10];

	count = 0;
	if (mode == 'u')
		dig = drop_nb(nb_digits, (unsigned int)num);
	else
	{
		num = manage_neg(num, &count);
		dig = drop_nb(nb_digits, num);
	}
	count += (dig + 1);
	while (dig >= 0)
	{
		write (1, (nb_digits + dig), 1);
		dig--;
	}
	return (count);
}

/*
unsigned int	pf_putfloat(double num)
{
	unsigned int	count;
	unsigned int	exponent;
	unsigned int	fraction;
	int				sign;

	count = 0;

	return (count);
}
*/