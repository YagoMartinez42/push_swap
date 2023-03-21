/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:07:27 by samartin          #+#    #+#             */
/*   Updated: 2022/10/01 18:10:23 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned int	pos;

	pos = 0;
	while (s[pos] != 0)
	{	
		if (s[pos] == (char)c)
			return ((char *)&s[pos]);
		pos++;
	}
	if (s[pos] == (char)c)
		return ((char *)&s[pos]);
	else
		return (0);
}
