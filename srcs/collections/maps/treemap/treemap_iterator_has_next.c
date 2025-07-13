/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_iterator_has_next.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:24:33 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 17:26:42 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

int	treemap_iterator_has_next(t_treemap_iterator *it)
{
	if (!it)
		return (0);
	return (it->stack_size > 0);
}
