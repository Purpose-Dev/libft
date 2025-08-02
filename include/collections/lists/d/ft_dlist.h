/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 01:51:45 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/07 02:02:06 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_dlist_node
{
	void				*data;
	struct s_dlist_node	*next;
	struct s_dlist_node	*prev;
}	t_dlist_node;

typedef struct s_dlist
{
	t_dlist_node	*head;
	size_t			size;
}	t_dlist;

t_dlist			*dlist_create(void);
void			dlist_destroy(t_dlist *list, void (*del)(void *));
t_dlist_node	*dlist_node_create(void *data);

int				dlist_push_back(t_dlist *list, void *data);
int				dlist_push_front(t_dlist *list, void *data);
int				dlist_insert_at(t_dlist *list, size_t index, void *data);
int				dlist_insert_after(t_dlist *list, t_dlist_node *node,
					void *data);
int				dlist_insert_before(t_dlist *list, t_dlist_node *node,
					void *data);

void			*dlist_pop_front(t_dlist *list);
void			*dlist_pop_back(t_dlist *list);
void			*dlist_remove_at(t_dlist *list, size_t index);
int				dlist_remove_node(t_dlist *list, t_dlist_node *node);
int				dlist_remove_data(t_dlist *list, void *data,
					int (*cmp)(void *, void *));

void			*dlist_get_front(t_dlist *list);
void			*dlist_get_back(t_dlist *list);
void			*dlist_get_at(t_dlist *list, size_t index);
t_dlist_node	*dlist_find(t_dlist *list, void *data,
					int (*cmp)(void *, void *));

size_t			dlist_size(t_dlist *list);
int				dlist_is_empty(t_dlist *list);
void			dlist_clear(t_dlist *list, void (*del)(void *));
void			dlist_reverse(t_dlist *list);

void			dlist_foreach(t_dlist *list, void (*f)(void *));
void			dlist_foreach_reverse(t_dlist *list, void (*f)(void *));
t_dlist_node	*dlist_next(t_dlist_node *node);
t_dlist_node	*dlist_prev(t_dlist_node *node);

#endif // FT_DLIST_H
