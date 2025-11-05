/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:56:45 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/05 09:53:04 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>

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

int			ft_fflush(t_ft_file *stream);
int			ft_fputc(int c, t_ft_file *stream);
int			ft_putc(int c, t_ft_file *stream);
int			ft_fputs(const char *s, t_ft_file *stream);
int			ft_puts(const char *s);
int			ft_putchar(int c);
long		ft_ftell(t_ft_file *stream);
int			ft_fseek(t_ft_file *stream, long offset, int whence);
int			ft_ferror(t_ft_file *stream);

int			ft_fstat(int fd, struct stat *restrict stat_buf);

#endif // FT_IO_H
