/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 15:07:34 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/10 22:39:46 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

typedef struct s_word
{
	int start_i;
	int end_i;
	int len;
} t_word;

static inline int is_word_start(int i, const char *s, char c)
{
	return (s[i] != c && (i == 0 || s[i - 1] == c));
}

static inline int is_word_end(int i, const char *s, char c)
{
	return (s[i] == c && i != 0 && s[i - 1] != c);
}

static int word_count(const char *s, char delim)
{
	int i = 0;
	int count = 0;

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
	return count;
}

// ===== Helper: count chars in a word =====
static int char_count(const char *s, char delim)
{
	int len = 0;
	while (s[len] && s[len] != delim)
		len++;
	return len;
}

// ===== Helper: free partial allocation =====
static char **clear_mem(char **s, int index)
{
	while (index >= 0)
	{
		free(s[index]);
		index--;
	}
	free(s);
	return NULL;
}

static int find_words (t_word *s_words, const char *s, char c)
{
	int	word_i;
	int	i;

	word_i = 0;
	i = 0;
	while (s[i])
	{
		if (is_word_start(i, s, c))				//s[i] != c && (i = 0 || s[i - 1] == c))
		{
			s_words[word_i].start_i = i;
			printf("word start: [ %c", s[i]);
		}
		else if (is_word_end(i, s, c)) 			//s[i] == c && s[i - 1] != c)
		{
			s_words[word_i].end_i = i - 1;
			s_words[word_i].len = s_words[word_i].end_i - s_words[word_i].start_i;
			printf("%c]\n\n", s[i]);
			word_i++;
			
			// printf("Word %d: [%.*s] (start_i=%d, end_i=%d, len=%d)\n",
			// word_i,
			// s_words[word_i].len,
			// &s[s_words[word_i].start_i],
			// s_words[word_i].start_i,
			// s_words[word_i].end_i,
			// s_words[word_i].len);
		}
		else
			if (s[i] != c) {printf("%c, ", s[i]);}
		i++;
	}
	return (word_i);
}


char **ft_split(const char *s, char c)
{
	char 	**new_strs;
	t_word	*s_words;
	int 	count;

	if (s == NULL || c == '\0')
	{
		return NULL;
	}
	count = word_count(s, c);
	new_strs = malloc((count + 1) * sizeof(char *));
	s_words = malloc((count + 1) * sizeof(t_word));
	if (!new_strs || !s_words)
	{
		return NULL;
	}
	
	find_words(s_words, s, c);

	// for (int i = 0; i < count; i++)
	// {
	// 	printf("Word %d: [%.*s] (start_i=%d, end_i=%d, len=%d)\n",
	// 		i,
	// 		s_words[i].len,
	// 		&s[s_words[i].start_i],
	// 		s_words[i].start_i,
	// 		s_words[i].end_i,
	// 		s_words[i].len);
	// }

	new_strs[count] = NULL;
	return (new_strs);
}

static void free_split(char **arr)
{
    if (!arr) return;
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

int	main(void)
{
	struct {
        const char *input;
        char delim;
        const char *expected[10];
    } tests[] = {
        {"a,b,c", ',', {"a", "b", "c", NULL}},
        {",a,,b,", ',', {"a", "b", NULL}},
        {",,,", ',', {NULL}},
        {"abc", ',', {"abc", NULL}},
        {"", ',', {NULL}},
		//{"\0aaa\0bb", '\0', {NULL}},
        {NULL, ',', {NULL}},
    };

	for (int t = 0; tests[t].input != NULL || tests[t].expected[0] != NULL; t++)
	{
        printf("Testing: '%s'\n", tests[t].input ? tests[t].input : "(null)");
        char **actual = ft_split(tests[t].input, tests[t].delim);
		printf("Freeing memory\n");
		free_split(actual);
	}
}