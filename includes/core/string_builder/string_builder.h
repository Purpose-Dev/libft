/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_builder.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:43:51 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 22:25:25 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_BUILDER_H
# define STRING_BUILDER_H

# include <stdarg.h>
# include <stdlib.h>

# define SB_INITIAL_CAPACITY 64
# define SB_GROWTH_FACTOR 2

typedef struct s_string_builder
{
	char	*buffer;
	size_t	length;
	size_t	capacity;
}	t_string_builder;

// Creation and destruction
t_string_builder	*sb_create(void);
t_string_builder	*sb_create_with_capacity(size_t capacity);
void				sb_destroy(t_string_builder *sb);
void				sb_clear(t_string_builder *sb);

// Appending operations
int					sb_ensure_capacity(t_string_builder *sb,
						size_t needed_capacity);
int					sb_append_char(t_string_builder *sb, char c);
int					sb_append_str(t_string_builder *sb, const char *str);
int					sb_append_substring(t_string_builder *sb, const char *str,
						size_t start, size_t len);
int					sb_append_int(t_string_builder *sb, int num);
int					sb_append_format(t_string_builder *sb, const char *format,
						...);

// Insertion operations
int					sb_insert_char(t_string_builder *sb, size_t index, char c);
int					sb_insert_str(t_string_builder *sb, size_t index,
						const char *str);

// Delete operations
int					sb_delete_char(t_string_builder *sb, size_t index);
int					sb_delete_range(t_string_builder *sb, size_t start,
						size_t end);

// Utility operations
char				*sb_to_string(t_string_builder *sb);
size_t				sb_length(t_string_builder *sb);
size_t				sb_capacity(t_string_builder *sb);
int					sb_is_empty(t_string_builder *sb);
void				sb_trim(t_string_builder *sb);

// Advanced operations
int					sb_reverse(t_string_builder *sb);
int					sb_replace(t_string_builder *sb, const char *old_str,
						const char *new_str);
int					sb_replace_char(t_string_builder *sb, char old_char,
						char new_char);

#endif // STRING_BUILDER_H
