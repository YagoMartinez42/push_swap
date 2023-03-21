/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:28:37 by samartin          #+#    #+#             */
/*   Updated: 2022/10/01 11:34:12 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim_it(char const *s1, char const *set, unsigned int *len)
{
	unsigned int	i;

	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			break ;
		s1++;
		(*len)--;
	}
	if (*len)
	{
		i = (*len) - 1;
		while (i >= 0)
		{
			if (!ft_strchr(set, s1[i]))
				break ;
			(*len)--;
			i--;
		}
	}
	return ((char *)s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	len;

	if (!s1 || !set)
		return (NULL);
	if (!(*s1))
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		else
		{
			*str = *s1;
			return (str);
		}
	}
	len = ft_strlen(s1);
	if (*set)
		s1 = trim_it(s1, set, &len);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy (str, s1, len + 1);
	return (str);
}
