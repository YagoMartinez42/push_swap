/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filem.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:06:15 by samartin          #+#    #+#             */
/*   Updated: 2023/02/09 16:00:47 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEM_H
# define FILEM_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
void	*gnl_mexpand(void *ptr, int size);
int		gnl_len(const char *str);
char	*gnl_strncat(char *dest, char *src, int nb);

#endif
