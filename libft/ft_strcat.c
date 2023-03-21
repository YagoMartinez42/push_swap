/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:45:40 by samartin          #+#    #+#             */
/*   Updated: 2023/01/13 12:43:16 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * It takes two strings and appends the second to the first. Enough allocated
 * space for the full string is to be supossed.
 * 
 * @param dest This is the destination string.
 * @param src The string to be appended.
 * 
 * @return The address of the first character of the string.
 */
char	*ft_strcat(char *dest, char *src)
{
	int	pos1;
	int	pos2;

	if (!dest)
		return (0);
	pos1 = 0;
	pos2 = 0;
	while (dest[pos1])
		pos1++;
	while (src && src[pos2])
	{
		dest[pos1] = src[pos2];
		pos1++;
		pos2++;
	}
	dest[pos1] = 0;
	return (dest);
}
