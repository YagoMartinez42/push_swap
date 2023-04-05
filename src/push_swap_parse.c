/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:36:01 by samartin          #+#    #+#             */
/*   Updated: 2023/04/05 15:12:02 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list	*ft_node_into_list(t_list *lst, int nbr)
{
	t_list		*node;
	t_idxd_node	*content;
	
	content = malloc(sizeof(t_idxd_node));
	content->value = nbr;
	node = ft_lst_new(content);
	if (!node)
		return (NULL);
	ft_lst_add_back(&lst, node);
	return (lst);
}

static t_list	*make_stack(char *parastr)
{
	char	*aux;
	t_list	*lst;
	int		nbr;
	int		*nbrp;

	nbrp = &nbr;
	aux = parastr;
	lst = NULL;
	while (*parastr)
	{
		nbrp = ps_atoi(&parastr, nbrp);
		if (!nbrp)
			return (NULL);
		lst = ft_node_into_list(lst, nbr);
		if (!lst)
			return (NULL);
	}
	free(aux);
	if (ft_lstsize(lst) < 1)
		return (NULL);
	return (lst);
}

t_list	*parse_args(size_t argc, char **argv)
{
	char	*parastr;
	t_list	*lst;

	parastr = make_args_single(argc, argv);
	lst = make_stack(parastr);
	if (!lst)
		return (NULL);
	return (lst);
}
