/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_compare_fs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:26:57 by samartin          #+#    #+#             */
/*   Updated: 2023/03/17 15:54:45 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	comp_sigd_asc(long a, long b)
{
	if (a <= b)
		return (1);
	return (0);
}

int	comp_unsd_asc(unsigned long a, unsigned long b)
{
	if (a <= b)
		return (1);
	return (0);
}

int	comp_sigd_desc(long a, long b)
{
	if (a >= b)
		return (1);
	return (0);
}

int	comp_unsd_desc(unsigned long a, unsigned long b)
{
	if (a >= b)
		return (1);
	return (0);
}
