/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:36:18 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/29 14:38:43 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"
#include "core/string_builder/string_builder.h"

char	*sb_to_string_and_destroy(t_string_builder *sb)
{
	char	*str;

	if (!sb)
		return (NULL);
	str = ft_strdup(sb->buffer);
	if (!str)
		return (NULL);
	free(sb->buffer);
	free(sb);
	return (str);
}
