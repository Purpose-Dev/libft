/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 02:07:57 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/07 02:37:57 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHMAP_H
# define FT_HASHMAP_H

# include <stddef.h>
# include <stdint.h>
#include "../ft_map_utils.h"

#ifndef HASHMAP_DEFAULT_CAPACITY
#  define HASHMAP_DEFAULT_CAPACITY 16
# endif // HASHMAP_DEFAULT_CAPACITY

# ifndef HASHMAP_DEFAULT_LOAD_FACTOR
#  define HASHMAP_DEFAULT_LOAD_FACTOR 0.75f
# endif // HASHMAP_DEFAULT_LOAD_FACTOR

# ifndef HASHMAP_MAX_LOAD_FACTOR
#  define HASHMAP_MAX_LOAD_FACTOR 0.9f
# endif // HASHMAP_MAX_LOAD_FACTOR

# ifndef HASHMAP_MIN_LOAD_FACTOR
#  define HASHMAP_MIN_LOAD_FACTOR 0.1f
# endif // HASHMAP_MIN_LOAD_FACTOR

typedef struct s_hashmap_entry
{
	void					*value;
	char					*key;
	struct s_hashmap_entry	*next;
	uint32_t				hash;
}	t_hashmap_entry;

typedef struct s_hashmap
{
	t_hashmap_entry	**buckets;
	uint32_t		(*hash_func)(const char *key);
	int				(*key_cmp)(const char *a, const char *b);
	size_t			capacity;
	size_t			size;
	size_t			threshold;
	float			load_factor;
}	t_hashmap;

typedef struct s_hashmap_iterator
{
	t_hashmap		*map;
	t_hashmap_entry	*current;
	t_hashmap_entry	*next;
	size_t			bucket_index;
}	t_hashmap_iterator;

t_hashmap			*hashmap_create(void);
t_hashmap			*hashmap_create_with_capacity(size_t initial_capacity);
t_hashmap			*hashmap_create_with_options(size_t capacity,
						float load_factor);
void				hashmap_destroy(t_hashmap *map, void (*value_del)(void *));
void				hashmap_clear(t_hashmap *map, void (*value_del)(void *));

int					hashmap_put(t_hashmap *map, const char *key, void *value);
void				*hashmap_get(t_hashmap *map, const char *key);
void				*hashmap_remove(t_hashmap *map, const char *key);
int					hashmap_contains_key(t_hashmap *map, const char *key);
int					hashmap_contains_value(t_hashmap *map, void *value,
						int (*cmp)(void *, void *));

int					hashmap_put_if_absent(t_hashmap *map, const char *key,
						void *value);
void				*hashmap_replace(t_hashmap *map, const char *key,
						void *new_value);
int					hashmap_replace_if_equals(t_hashmap *map, const char *key,
						void *old_value, void *new_value);

size_t				hashmap_size(t_hashmap *map);
int					hashmap_is_empty(t_hashmap *map);
char				**hashmap_keys(t_hashmap *map);
void				**hashmap_values(t_hashmap *map);

t_hashmap_iterator	*hashmap_iterator_create(t_hashmap *map);
int					hashmap_iterator_has_next(t_hashmap_iterator *it);
t_hashmap_entry		*hashmap_iterator_next(t_hashmap_iterator *it);
void				hashmap_iterator_destroy(t_hashmap_iterator *it);
void				hashmap_foreach(t_hashmap *map,
						void (*f)(const char *key, void *value));

uint32_t			hashmap_djb2_hash(const char *key);
uint32_t			hashmap_fnv1a_hash(const char *key);
uint32_t			hashmap_murmur3_hash(const char *key);

#endif // FT_HASHMAP_H
