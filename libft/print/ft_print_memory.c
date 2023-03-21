/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:50:13 by samartin          #+#    #+#             */
/*   Updated: 2022/12/14 13:34:29 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	print_addr(void *addr)
{
	char	*addr_line;
	int		len;

	addr_line = ft_itoab((long)addr, 16);
	len = 0;
	while (addr_line[len] != '\0')
		len++;
	while (len < 16)
	{
		ft_putstr_fd ("0", 1);
		len++;
	}
	ft_putstr_fd (addr_line, 1);
	ft_putstr_fd (": ", 1);
	free(addr_line);
}

static void	print_val(char *sym_line, void *addr, unsigned int pos)
{
	unsigned char	c;
	char			*pair;

	if (!addr)
	{
		ft_putstr_fd ("  ", 1);
		sym_line[pos % 16] = '\0';
	}
	else
	{
		c = *(unsigned char *)addr;
		if (c < 16)
			ft_putstr_fd("0", 1);
		pair = ft_itoab(c, 16);
		ft_putstr_fd(pair, 1);
		free (pair);
		if (c >= ' ' && c <= '~')
			sym_line[pos % 16] = c;
		else
			sym_line[pos % 16] = '.';
	}
	if (pos % 2 == 1)
		ft_putstr_fd (" ", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*sym_line;
	unsigned int	pos;

	sym_line = malloc (18 * sizeof(char));
	sym_line[16] = '\n';
	sym_line[17] = '\0';
	pos = 0;
	while (!(pos >= size && (pos % 16) == 0))
	{
		if (pos % 16 == 0)
			print_addr(addr + pos);
		if (pos < size)
			print_val(sym_line, addr + pos, pos);
		else
			print_val(sym_line, 0, pos);
		pos++;
		if (pos % 16 == 0)
			ft_putstr_fd (sym_line, 1);
	}
	free (sym_line);
	return (addr);
}
