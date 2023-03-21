/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:22:04 by samartin          #+#    #+#             */
/*   Updated: 2022/10/01 13:47:50 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	drop_d(char *str, int n, int sign)
{
	unsigned int	dig;

	dig = 0;
	if (n == -2147483648)
	{
		str[0] = '8';
		n = n / 10;
		dig++;
	}
	while ((n * sign) >= 10)
	{
		str[dig] = ((n % 10) * sign) + '0';
		n = n / 10;
		dig++;
	}
	str[dig] = (n * sign) + '0';
	if (sign == -1)
	{
		dig++;
		str[dig] = '-';
	}
	str[dig + 1] = '\0';
	return (dig + 1);
}

static void	rev_str(char *str_dst, char *str_org, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		str_dst[i] = str_org[len - i - 1];
		i++;
	}
	str_dst[i] = '\0';
}

char	*ft_itoa(int n)
{
	char			strswp[12];
	char			*nb_as_str;
	unsigned int	dig;
	int				sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	dig = drop_d (strswp, n, sign);
	nb_as_str = malloc ((dig + 1) * (sizeof(char)));
	if (!nb_as_str)
		return (NULL);
	rev_str(nb_as_str, strswp, dig);
	return (nb_as_str);
}
