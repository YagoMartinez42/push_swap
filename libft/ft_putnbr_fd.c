/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:21:21 by samartin          #+#    #+#             */
/*   Updated: 2022/09/28 16:14:34 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	drop_nb(char *nbdigs, int n)
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

void	ft_putnbr_fd(int n, int fd)
{
	int		dig;
	char	nb_digits [10];

	if (n == -2147483648)
	{
		write (fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = n * -1;
	}
	dig = drop_nb(nb_digits, n);
	while (dig >= 0)
	{
		write (fd, (nb_digits + dig), 1);
		dig--;
	}
}
