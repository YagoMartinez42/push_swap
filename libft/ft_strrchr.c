/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:31:34 by samartin          #+#    #+#             */
/*   Updated: 2022/11/09 14:13:41 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	pos;

	pos = 0;
	while (s[pos] != 0)
		pos++;
	while (pos >= 0)
	{
		if (s[pos] == (char)c)
			return ((char *)s + pos);
		pos--;
	}
	return (0);
}
