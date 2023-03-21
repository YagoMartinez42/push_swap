/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:33:56 by samartin          #+#    #+#             */
/*   Updated: 2023/01/04 17:23:44 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * It appends the null-terminated string src to the end of dst. It will append
 * at most dstsize - strlen(dst) - 1 bytes, NULL-terminating the result
 * 
 * @param dst The destination string.
 * @param src The string to be appended.
 * @param dstsize The size of the destination buffer.
 * 
 * @return The length of the string it tried to create in the buffer.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	pos1;
	size_t	pos2;
	size_t	ret;
	size_t	endp;

	pos1 = 0;
	while (dst && dst[pos1])
		pos1++;
	if (pos1 < dstsize)
		ret = pos1;
	else
		ret = dstsize;
	pos2 = -1;
	endp = 0;
	while (src[++pos2])
	{
		if ((pos1 + pos2) < (dstsize - 1) && dstsize > 0)
		{
			dst[pos1 + pos2] = src[pos2];
			endp++;
		}
	}
	if (dstsize != 0 && dstsize >= pos1)
		dst[pos1 + endp] = '\0';
	return (ret + pos2);
}
