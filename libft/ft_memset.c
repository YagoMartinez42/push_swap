/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:47:12 by samartin          #+#    #+#             */
/*   Updated: 2022/09/14 11:42:39 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*mempoint;

	mempoint = b;
	while (len > 0)
	{
		*mempoint = (unsigned char)c;
		mempoint++;
		len--;
	}
	return (b);
}
