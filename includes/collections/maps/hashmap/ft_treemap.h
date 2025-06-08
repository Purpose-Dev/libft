/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treemap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 02:27:56 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/07 02:38:48 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREEMAP_H
# define FT_TREEMAP_H

# include <stddef.h>
#include "../ft_map_utils.h"

typedef enum e_rb_color
{
	RB_RED,
	RB_BLACK
}	t_rb_color;

typedef struct s_treemap_node
{
	char					*key;
	void					*value;
	struct s_treemap_node	*left;
	struct s_treemap_node	*right;
	struct s_treemap_node	*parent;
	t_rb_color				color;
}	t_treemap_node;

typedef struct s_treemap
{
	t_treemap_node	*root;
	t_treemap_node	*nil;
	int				(*key_cmp)(const char *a, const char *b);
	size_t			size;
}	t_treemap;

typedef struct s_treemap_iterator
{
	t_treemap		*map;
	t_treemap_node	*current;
	t_treemap_node	**stack;
	size_t			stack_size;
	size_t			stack_capacity;
	int				reverse;
}	t_treemap_iterator;

t_treemap			*treemap_create(void);
t_treemap			*treemap_create_with_comparator(
						int (*cmp)(const char *, const char *));
void				treemap_destroy(t_treemap *map, void (*value_del)(void *));
void				treemap_clear(t_treemap *map, void (*value_del)(void *));

int					treemap_put(t_treemap *map, const char *key, void *value);
void				*treemap_get(t_treemap *map, const char *key);
void				*treemap_remove(t_treemap *map, const char *key);
int					treemap_contains_key(t_treemap *map, const char *key);
int					treemap_contains_value(t_treemap *map, void *value,
						int (*cmp)(void *, void *));

char				*treemap_first_key(t_treemap *map);
char				*treemap_last_key(t_treemap *map);
void				*treemap_first_value(t_treemap *map);
void				*treemap_last_value(t_treemap *map);
char				*treemap_lower_key(t_treemap *map, const char *key);
char				*treemap_higher_key(t_treemap *map, const char *key);
char				*treemap_floor_key(t_treemap *map, const char *key);
char				*treemap_ceiling_key(t_treemap *map, const char *key);

void				*treemap_poll_first(t_treemap *map);
void				*treemap_poll_last(t_treemap *map);

t_treemap			*treemap_submap(t_treemap *map, const char *from_key,
						const char *to_key);
t_treemap			*treemap_head_map(t_treemap *map, const char *to_key);
t_treemap			*treemap_tail_map(t_treemap *map, const char *from_key);

size_t				treemap_size(t_treemap *map);
int					treemap_is_empty(t_treemap *map);
char				**treemap_keys(t_treemap *map);
void				**treemap_values(t_treemap *map);

t_treemap_iterator	*treemap_iterator_create(t_treemap *map);
t_treemap_iterator	*treemap_reverse_iterator_create(t_treemap *map);
int					treemap_iterator_has_next(t_treemap_iterator *it);
t_treemap_node		*treemap_iterator_next(t_treemap_iterator *it);
void				treemap_iterator_destroy(t_treemap_iterator *it);
void				treemap_foreach(t_treemap *map,
						void (*f)(const char *key, void *value));
void				treemap_foreach_reverse(t_treemap *map,
						void (*f)(const char *key, void *value));

void				treemap_inorder(t_treemap *map,
						void (*f)(const char *key, void *value));
void				treemap_preorder(t_treemap *map,
						void (*f)(const char *key, void *value));
void				treemap_postorder(t_treemap *map,
						void (*f)(const char *key, void *value));

int					treemap_is_valid_rb_tree(t_treemap *map);
size_t				treemap_height(t_treemap *map);
size_t				treemap_black_height(t_treemap *map);

#endif // FT_TREEMAP_H
