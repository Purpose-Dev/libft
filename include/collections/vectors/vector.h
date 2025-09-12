/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 03:25:15 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/12 03:31:51 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>
# include <stdint.h>
# include <sys/types.h>

typedef enum e_result
{
	RESULT_OK,
	RESULT_ERROR,
	RESULT_OVERFLOW,
	RESULT_EOF,
	RESULT_INVAL,
	RESULT_READ_ERROR,
	RESULT_UNKNOWN
}	t_result;

typedef enum e_type
{
	TYPE_UNDEFINED,
	TYPE_OTHER,
}	t_type;

typedef union u_any
{
	void		*ptr;
	char		*str;
	uint64_t	u64;
	int64_t		i64;
	uint32_t	u32;
	int32_t		i32;
	_Float32	f32;
	_Float64	f64;
}	t_any;

typedef struct s_value
{
	t_type	type;
	int		reserved;
	t_any	value;
}	t_value;

typedef struct s_vector
{
	size_t	length;
	size_t	capacity;
	size_t	offset;
	t_value	*data;
}	t_vector;

t_value		ft_gen_val(t_type type, t_any value);

t_result	ft_vector_init(t_vector *vec, size_t size);
t_result	ft_vector_resize(t_vector *vec, size_t size);
void		ft_vector_free(t_vector *vec);
void		ft_vector_foreach(t_vector *vec,
				void (*fn)(size_t idx, t_value data));
void		ft_vector_map(t_vector *vec,
				t_value (*fn)(size_t idx, t_value data));
_Bool		ft_vector_every(t_vector *vec,
				_Bool (*fn)(size_t idx, t_value data));
_Bool		ft_vector_some(t_vector *vec,
				_Bool (*fn)(size_t idx, t_value data));
t_value		ft_vector_pop(t_vector *vec);
t_value		ft_vector_shift(t_vector *vec);
t_result	ft_vector_push(t_vector *vec, t_value value);
t_result	ft_vector_unshift(t_vector *vec, t_value value);
t_value		ft_vector_at(t_vector *vec, ssize_t idx);

#endif // VECTOR_H
