/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_create_with_capacity.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 03:07:04 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 05:49:33 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

t_hashmap	*hashmap_create_with_capacity(size_t initial_capacity)
{
	return (hashmap_create_with_options(initial_capacity,
			HASHMAP_DEFAULT_LOAD_FACTOR));
}
