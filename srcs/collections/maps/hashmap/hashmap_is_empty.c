/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_is_empty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:07:48 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 08:09:16 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

int	hashmap_is_empty(t_hashmap *map)
{
	return (hashmap_size(map) == 0);
}
