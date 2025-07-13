/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_iterator_destroy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:24:49 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 17:26:56 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

void	treemap_iterator_destroy(t_treemap_iterator *it)
{
	if (!it)
		return ;
	free(it->stack);
	free(it);
}
