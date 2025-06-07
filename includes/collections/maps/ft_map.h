/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 02:29:16 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/07 02:29:59 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

int		str_compare(const char *a, const char *b);
int		str_compare_ignorecase(const char *a, const char *b);
int		numeric_str_compare(const char *a, const char *b);

char	*key_duplicate(const char *key);
void	key_free(char *key);

#endif // FT_MAP_H
