/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:06:37 by samartin          #+#    #+#             */
/*   Updated: 2023/03/15 11:36:29 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filem.h"

static void	displace_buffer(char *buf, int pos)
{
	int	i;

	i = 0;
	if (buf[pos + i] == '\0')
		buf[0] = '\0';
	while (buf[pos + i] != '\0')
	{
		buf[i] = buf[pos + i];
		i++;
	}
	buf[i] = '\0';
}

static char	*append_chnk(char **line, char *buf)
{
	int	i;
	int	line_len;

	i = 0;
	line_len = 0;
	if (*buf == '\0')
		i++;
	if (*line)
		line_len = gnl_len(*line);
	while (*(buf + i) && *(buf + i) != '\n')
		i++;
	if (*(buf + i) == '\n')
		i++;
	if (i == 0)
		return (NULL);
	*line = (char *)gnl_mexpand(*line, line_len + i + 1);
	*line = gnl_strncat(*line, buf, i);
	displace_buffer(buf, i);
	return (buf);
}

static char	*clear_buffer(char *buf)
{
	int	i;

	if (buf)
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			buf[i] = '\0';
			i++;
		}
		free (buf);
	}
	return (NULL);
}

static char	*fill_buffer(int fd, char *buf)
{
	int	buff_len;

	if (*buf == '\0')
	{
		buff_len = read(fd, buf, BUFFER_SIZE);
		if (buff_len < 1)
		{
			free (buf);
			buf = NULL;
			return (buf);
		}
		buf[buff_len] = '\0';
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf[512];

	if (fd < 0 || fd > 511 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		if (fd >= 0 && fd <= 511)
			buf[fd] = clear_buffer(buf[fd]);
		return (NULL);
	}
	if (!(buf[fd]))
	{
		buf[fd] = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
		if (!(buf[fd]))
			return (NULL);
		*(buf[fd]) = '\0';
	}
	line = NULL;
	while (!line || (line[gnl_len(line) - 1] != '\n'))
	{
		buf[fd] = fill_buffer(fd, buf[fd]);
		if (!(buf[fd]) || *(buf[fd]) == '\0')
			break ;
		buf[fd] = append_chnk(&line, buf[fd]);
	}
	return (line);
}
