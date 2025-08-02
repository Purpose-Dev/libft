/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf_table_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:26:31 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 17:36:02 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/fonts/ttf_internal.h"

t_ttf_table_record	*ttf_find_table(t_ttf_font *font, const uint32_t tag)
{
	uint16_t	i;

	if (!font)
		return (NULL);
	i = 0;
	while (i < font->num_tables)
	{
		if (font->tables[i].tag == tag)
			return (&font->tables[i]);
		i++;
	}
	return (NULL);
}

bool	ttf_validate_table_access(t_ttf_font *font, const uint32_t offset,
									const uint32_t length)
{
	if (!font || !font->data)
		return (false);
	if (offset >= font->data_size)
		return (false);
	if (offset + length > font->data_size)
		return (false);
	return (true);
}

uint8_t	*ttf_get_table_data(t_ttf_font *font, const uint32_t tag)
{
	t_ttf_table_record	*table;

	table = ttf_find_table(font, tag);
	if (!table)
		return (NULL);
	if (!ttf_validate_table_access(font, table->offset, table->length))
		return (NULL);
	return (font->data + table->offset);
}
