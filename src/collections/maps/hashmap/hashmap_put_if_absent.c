/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_put_if_absent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 06:18:52 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 06:20:48 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

int	hashmap_put_if_absent(t_hashmap *map, const char *key, void *value)
{
	if (!map || !key)
		return (0);
	if (hashmap_contains_key(map, key))
		return (0);
	return (hashmap_put(map, key, value));
}
