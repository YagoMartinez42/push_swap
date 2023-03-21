/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:14:48 by samartin          #+#    #+#             */
/*   Updated: 2023/02/09 16:15:47 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function takes a string, a number, a base, and a sign, places in the
 * string a reversed representation of the number in the given base and returns
 * the number of digits in the string
 * 
 * @param str the string that will be returned.
 * @param n the number to be converted.
 * @param base the base of the number.
 * @param sign 1 if positive, -1 if negative.
 * 
 * @return The number of digits in the string.
 */
static int	drop_d(char *str, long n, unsigned int base, int sign)
{
	unsigned long	dig;
	char			base_symbols[33];

	dig = 0;
	ft_strcpy(base_symbols, "0123456789ABCDEFGHIJKLMNOPQRSTUV");
	while ((n * sign) >= base)
	{
		str[dig] = base_symbols[(n % base) * sign];
		n = n / base;
		dig++;
	}
	str[dig] = base_symbols[n * sign];
	if (sign == -1)
	{
		dig++;
		str[dig] = '-';
	}
	str[dig + 1] = '\0';
	return (dig + 1);
}

/**
 * It reverses a string copying it in another one.
 * 
 * @param str_dst The destination string.
 * @param str_org The original string.
 * @param len the length of the string to be reversed.
 */
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

/**
 * It takes a number and a base, and returns a string representing the number in
 * the given base.
 * 
 * @param n the number to convert.
 * @param base the base of the number to be converted.
 * 
 * @return A string of characters that represent the number in the base given.
 */
char	*ft_itoab(long n, unsigned int base)
{
	char			strswp[66];
	char			*nb_as_str;
	unsigned long	dig;
	int				sign;

	if (base <= 32)
	{
		if (n < 0)
			sign = -1;
		else
			sign = 1;
		dig = drop_d (strswp, n, base, sign);
		nb_as_str = malloc ((dig + 1) * sizeof(char));
		if (!nb_as_str)
			return (0);
		rev_str(nb_as_str, strswp, dig);
	}
	else
		return (NULL);
	return (nb_as_str);
}
