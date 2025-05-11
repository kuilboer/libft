/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 15:07:34 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/11 20:02:32 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static void	clear_mem(char **arr, t_word *strc_arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
	if (strc_arr)
		free(strc_arr);
	return ;
}

static int	word_count(const char *s, char delim)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == delim)
			i++;
		if (s[i] && s[i] != delim)
		{
			count++;
			while (s[i] && s[i] != delim)
				i++;
		}
	}
	return (count);
}

static int	find_words(t_word *s_words, const char *s, char c)
{
	int		in_word;
	size_t	word_i;
	size_t	i;

	in_word = 0;
	word_i = 0;
	i = 0;
	while (s[i] || in_word == 1)
	{
		if (s[i] != c && in_word == 0)
		{
			s_words[word_i].start_i = i;
			s_words[word_i].end_i = 0;
			s_words[word_i].len = 1;
			in_word = 1;
		}
		else if ((s[i] == c || !s[i]) && in_word == 1)
		{
			s_words[word_i].end_i = i;
			s_words[word_i].len = i - s_words[word_i].start_i;
			word_i++;
			in_word = 0;
		}
		if (!s[i])
			break ;
		i++;
	}
	return (word_i);
}

static int	copy_words(char **new_strs,	const char *s,
	t_word *s_words,	size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		new_strs[i] = (char *)malloc(sizeof(char) * (s_words[i].len + 1));
		if (!new_strs[i])
			clear_mem(new_strs, s_words);
		ft_memcpy(new_strs[i], &s[s_words[i].start_i], s_words[i].len);
		new_strs[i][s_words[i].len] = '\0';
		i++;
	}
	new_strs[count] = NULL;
	return (i);
}

char	**ft_split(const char *s, char c)
{
	char	**new_strs;
	t_word	*s_words;
	size_t	count;

	if (s == NULL )
		return (NULL);
	count = word_count(s, c);
	new_strs = malloc((count + 1) * sizeof(char *));
	s_words = malloc(count * sizeof(t_word));
	if (!new_strs || !s_words)
	{
		clear_mem(new_strs, s_words);
		return (NULL);
	}
	find_words(s_words, s, c);
	copy_words(new_strs, s, s_words, count);
	free(s_words);
	return (new_strs);
}
