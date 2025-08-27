/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:55:28 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/08/27 03:47:56 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <errno.h>
# include <stdarg.h>
# include <stddef.h>
# include <sys/types.h>

# include "core/stdlib/ft_stdlib.h"

size_t		ft_strlen(const char *s);
size_t		ft_strnlen(const char *s, size_t max_length);
ssize_t		ft_strlen_s(const char *s);
char		*ft_strcpy(char *dest, const char *src);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strcat(char *dest, const char *src);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strncat(char *dest, const char *src, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t		ft_strcspn(const char *s, const char *reject);
size_t		ft_strspn(const char *s, const char *accept);
char		*ft_strtok(char *str, const char *delim);
const char	*ft_strpbrk(const char *s, const char *accept);
const char	*ft_strerror(int errnum);

char		*ft_itoa(int n);
char		*ft_ltoa(long n);
char		*ft_utoa(unsigned int n);
char		*ft_ftoa(double f, int precision);

char		*ft_strdup(const char *s);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s1, const char *set);
char		**ft_split(const char *s, char c);

char		*ft_strjoin_multiple(int count, ...);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif // FT_STRING_H
