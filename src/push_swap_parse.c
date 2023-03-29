/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:36:01 by samartin          #+#    #+#             */
/*   Updated: 2023/03/29 16:37:24 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ps_atoi(char **str, int *nbp)
{
	long long	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while (**str == ' ')
		(*str)++;
	if (**str == '-')
		sign = -1;
	if (**str == '-' || **str == '+')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		nb = (nb * 10) + **str - '0';
		(*str)++;
	}
	nb = nb * sign;
	if (nb > __INT_MAX__ || nb < (-(__INT_MAX__) - 1) || \
			(**str != ' ' && **str != '\0'))
		return (NULL);
	else
	{
		*nbp = (int)nb;
		return (nbp);
	}
}

static void	ws_to_space(char *str)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (str[i] >= '\t' && str[i] <= '\r')
			str[i] = ' ';
		i++;
	}
}

static char	*make_args_single(size_t argc, char **argv)
{
	char	*parastr;
	char	*aux;
	size_t	i;

	parastr = malloc(1);
	*parastr = 0;
	i = 0;
	while (i < argc)
	{
		aux = parastr;
		parastr = malloc((ft_strlen(aux) + ft_strlen(argv[i + 1]) + 2) \
			* sizeof(char));
		parastr = ft_strcpy (parastr, aux);
		parastr = ft_strcat(parastr, argv[i + 1]);
		parastr = ft_strcat(parastr, " ");
		free (aux);
		i++;
	}
	ws_to_space(parastr);
	parastr[ft_strlen(parastr) - 1] = '\0';
	return (parastr);
}

static t_bllist	*make_stack(char *parastr)
{
	char		*aux;
	t_bllist	*node;
	t_bllist	*lst;
	int			nbr;
	int			*nbrp;

	nbrp = &nbr;
	aux = parastr;
	lst = NULL;
	while (*parastr)
	{
		nbrp = ps_atoi(&parastr, nbrp);
		if (!nbrp)
			return (NULL);
		node = ft_bllst_new(nbr);
		if (!node)
			return (NULL);
		ft_bllst_add_back(&lst, node);
	}
	free(aux);
	if (ft_bllst_size(node) < 1)
		return (NULL);
	return (ft_bllst_first(node));
}

t_bllist	*parse_args(size_t argc, char **argv)
{
	char		*parastr;
	t_bllist	*lst;

	parastr = make_args_single(argc, argv);
	lst = make_stack(parastr);
	if (!lst)
		return (NULL);
	return (lst);
}
