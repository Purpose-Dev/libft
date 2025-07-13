/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 01:40:42 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 01:52:18 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REGEX_H
# define FT_REGEX_H

# include <stdbool.h>
# include <stdlib.h>

# define REGEX_MAX_STATES 256
# define REGEX_MAX_GROUPS 16

typedef enum e_regex_token_type
{
	TOKEN_CHAR,
	TOKEN_DOT,
	TOKEN_STAR,
	TOKEN_PLUS,
	TOKEN_QUESTION,
	TOKEN_BRACKET_OPEN,
	TOKEN_BRACKET_CLOSE,
	TOKEN_PAREN_OPEN,
	TOKEN_PAREN_CLOSE,
	TOKEN_ANCHOR_START,
	TOKEN_ANCHOR_END,
	TOKEN_ESCAPE,
	TOKEN_END
}	t_regex_token_type;

typedef struct s_regex_token
{
	struct s_regex_token	*next;
	t_regex_token_type		type;
	char					value;
}	t_regex_token;

typedef struct s_regex_match {
	int		start;
	int		end;
	char	*matched_text;
}	t_regex_match;

typedef struct s_regex_state {
	int		state_id;
	bool	is_final;
	char	match_char;
	bool	is_any_char;
	int		next_state[2];
}	t_regex_state;

typedef struct s_regex {
	char			*pattern;
	t_regex_state	*states;
	int				num_states;
	int				start_state;
	bool			compiled;
}	t_regex;

// Regex compilation
t_regex	*regex_compile(const char *pattern);
void	regex_destroy(t_regex *regex);

// Regex matching
bool	regex_match(t_regex *regex, const char *text);
bool	regex_search(t_regex *regex, const char *text,
			t_regex_match *match);
int		regex_find_all(t_regex *regex, const char *text,
			t_regex_match *matches, int max_matches);

// Utility funcs
bool	regex_is_valid_pattern(const char *pattern);
char	*regex_replace(const char *text, t_regex *regex,
			const char *replacement);
char	*regex_replace_all(const char *text, t_regex *regex,
			const char *replacement);

// Pattern matching helpers
bool	regex_match_char(char pattern_char, char text_char);
bool	regex_match_any(char text_char);
bool	regex_match_range(const char *range, char text_char);

#endif // FT_REGEX_H
