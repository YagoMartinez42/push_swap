/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:54:56 by samartin          #+#    #+#             */
/*   Updated: 2022/10/01 11:38:55 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	unsigned int	i;
	unsigned int	wd_flg;
	unsigned int	count;

	i = 0;
	wd_flg = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			if (wd_flg == 1)
				wd_flg = 0;
		}
		else
		{
			if (wd_flg == 0)
			{
				wd_flg = 1;
				count++;
			}
		}
		i++;
	}
	return (count);
}

static const char	*add_word(const char *s, char c, char **ws, unsigned int i)
{
	unsigned int	len;
	unsigned int	j;

	len = 0;
	while (s[len] != c && s[len] != 0)
		len++;
	ws[i] = malloc (sizeof(char) * (len + 1));
	if (!ws[i])
	{
		while (i--)
			free(ws[i]);
		free(ws[i]);
		return (NULL);
	}
	j = 0;
	while (j < len)
	{
		ws[i][j] = *s;
		s++;
		j++;
	}
	ws[i][j] = '\0';
	return (s);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	str_count;
	char			**words;

	if (!s)
		return (NULL);
	str_count = count_words(s, c);
	words = malloc (sizeof(char *) * (str_count + 1));
	if (!words)
		return (NULL);
	i = 0;
	while (i < str_count)
	{
		while (*s == c)
			s++;
		s = add_word(s, c, words, i);
		if (!s)
		{
			free (words);
			return (NULL);
		}
		i++;
	}
	words[i] = NULL;
	return (words);
}
