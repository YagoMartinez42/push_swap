/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:28:48 by samartin          #+#    #+#             */
/*   Updated: 2022/12/02 15:37:58 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTS_H
# define FT_PRINTS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *format, ...);
unsigned int	pf_putchar(int chr);
unsigned int	pf_putstr(char *str);
unsigned int	pf_putint(int num, char mode);
unsigned int	pf_puthex(unsigned int num, char *hex_symbols);
unsigned int	pf_putaddr(void *addr);
unsigned int	pf_putfloat(double num);
void			*ft_print_memory(void *addr, unsigned int size);

#endif