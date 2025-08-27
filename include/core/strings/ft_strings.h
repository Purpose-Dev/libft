/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 02:33:16 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/08/27 02:37:01 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRINGS_H
# define FT_STRINGS_H

# include <stddef.h>

int		ft_strcasecmp(const char *s1, const char *s2);
int		ft_strncasecmp(const char *s1, const char *s2, size_t n);
char	*ft_index(const char *s, int c);
char	*ft_rindex(const char *s, int c);
int		ft_ffs(int i);

#endif // FT_STRINGS_H
