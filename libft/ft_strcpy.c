/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:48:23 by samartin          #+#    #+#             */
/*   Updated: 2022/07/18 19:51:23 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	pos;

	pos = -1;
	while (src[++pos] != 0)
		dest[pos] = src[pos];
	dest[pos] = src[pos];
	return (dest);
}
