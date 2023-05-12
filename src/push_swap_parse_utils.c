/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:55:52 by samartin          #+#    #+#             */
/*   Updated: 2023/05/12 13:03:07 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ps_atoi(char **str, int *nbp)
{
	long long	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while (**str == ' ')
		(*str)++;
	if (**str == '-')
		sign = -1;
	if ((**str == '-' || **str == '+') && *((*str) + 1) >= '0' &&
		*((*str) + 1) <= '9')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		nb = (nb * 10) + **str - '0';
		(*str)++;
	}
	nb = nb * sign;
	if (nb > __INT_MAX__ || nb < (-(__INT_MAX__) - 1) || \
			(**str != ' ' && **str != '\0'))
		return (NULL);
	else
	{
		*nbp = (int)nb;
		return (nbp);
	}
}

void	ws_to_space(char *str)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (str[i] >= '\t' && str[i] <= '\r')
			str[i] = ' ';
		i++;
	}
}
