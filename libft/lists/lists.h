/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:33:13 by samartin          #+#    #+#             */
/*   Updated: 2023/03/17 12:57:45 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H
# include <stdlib.h>
# include "aux_list_fs.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_bllist
{
	long			content;
	struct s_bllist	*next;
	struct s_bllist	*prev;
}	t_bllist;

void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
void		ft_lstremove_if(t_list **lst, void *data_ref, int (*cmp)(void *, \
void *));
int			ft_lstsize(t_list *lst);
t_list		*ft_lstsort(t_list *lst, int (*cmp)(long, long));
void		ft_bllst_add_back(t_bllist **lst, t_bllist *new);
void		ft_bllst_add_front(t_bllist **lst, t_bllist *new);
t_bllist	*ft_bllst_bubsort(t_bllist *lst, int (*cmp)(long, long));
void		ft_bllst_clear(t_bllist *lst);
t_bllist	*ft_bllst_first(t_bllist *lst);
void		ft_bllst_iter(t_bllist *lst, void (*f)(long));
t_bllist	*ft_bllst_last(t_bllist *lst);
t_bllist	*ft_bllst_new(long content);
t_bllist	*ft_bllst_remove_node(t_bllist *node);
int			ft_bllst_size(t_bllist *lst);

#endif