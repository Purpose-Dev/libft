/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:56:45 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/10/26 19:57:03 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <stdio.h>
# include <stdlib.h>

# ifdef _WIN32
#  ifndef STDIN_FILENO
#   define STDIN_FILENO 0
#  endif
#  ifndef STDOUT_FILENO
#   define STDOUT_FILENO 1
#  endif
#  ifndef STDERR_FILENO
#   define STDERR_FILENO 2
#  endif
# else
#  include <unistd.h>
# endif

# define FT_EOF (-1)
# define FT_BUFFER_SIZE 8192

typedef struct s_ft_file
{
	char	*buffer;
	size_t	buffer_size;
	size_t	buffer_pos;
	size_t	buffer_len;
	int		fd;
	int		eof;
	int		error;
	char	padding[4];
}	t_ft_file;

t_ft_file	*ft_stdin(void);
t_ft_file	*ft_stdout(void);
t_ft_file	*ft_stderr(void);

t_ft_file	*ft_fopen(const char *filename, const char *mode);
ssize_t		ft_fclose(t_ft_file *stream);
int			ft_fgetc(t_ft_file *stream);
int			ft_getc(t_ft_file *stream);
int			ft_getchar(void);
char		*ft_fgets(char *str, int size, t_ft_file *stream);
size_t		ft_fread(void *ptr, size_t size, size_t count, t_ft_file *stream);
ssize_t		ft_fwrite(const void *ptr, size_t size, size_t count,
				t_ft_file *stream);
ssize_t		ft_getline(char **line_ptr, size_t *n, t_ft_file *stream);
int			ft_feof(t_ft_file *stream);

#endif // FT_IO_H
