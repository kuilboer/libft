/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 15:07:34 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/10 00:04:52 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int word_count(char const *s, char delim)
{
	int		i;
	size_t	count;


	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == delim)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != delim)
			i++;
	}
	return (count);
}

static int char_count(char const *s, char delim)
{
	int		len;

	len = 0;
	while (s[len] && s[len] != delim) 
		len++;
	return (len);
}

static char **clear_mem(char **s, int index)
{
	while (index >= 0)
		free(s[index--]);
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**new_strs;
	int		count;
	int		word_i;
	int		char_i;
	int		i;
	
	if (s == NULL || c == '\0')
		return (NULL);
	printf("\n=========================================================================\n");
	printf("ft_split()\n");
	printf("=========================================================================\n");
	printf("String           = [ %s ]\n", s ? s : "NULL");
	printf("Delimiter char.  = [ %c ]\n", c);
	count = word_count(s, c);
	printf("Input word count = %d\n", count);
	new_strs = malloc(((count + 1) * sizeof(char*)));
	if (!new_strs)
		return (NULL);
	printf("new_str[] length = %d\n", count + 1);
	printf("=========================================================================\n");
	word_i = 0;
	i = 0;
	while (s[i])
	{
		printf("\tentering outer while loop\n");
		while (s[i] && s[i] == c)
		{
			printf("\t\tInner loop1, s[%d]: Skipping delimiter char: %c\n", i,s[i]);
			i++;
		}
		if (s[i] && s[i] != c)
		{
			printf("\n\t\tInner if condition, s[%d]: found non-delimiter char: %c\n\n", i, s[i]);
			new_strs[word_i] = malloc(char_count(&s[i], c) + 1);
			if (!new_strs[word_i])
				return (clear_mem(new_strs, word_i));
			printf("\t\tallocated memory for word[%d] at s[%d] = '%c'\n", word_i, i, s[i]);
			printf("\t\t\tInner loop2, s[%d]: Getting all word[%d] characters: [", i, word_i);
			char_i = 0;
			while (s[i] && s[i] != c)
			{
				new_strs[word_i][char_i++] = s[i++];
				printf("%c, ", new_strs[word_i][char_i - 1]);
			}
			printf("\\0");
			printf("]\n");
			new_strs[word_i][char_i] = '\0';
			word_i++;
		}
		printf("\n\touter while loop, s[%d]: Searching for next word[%d]\n\n", i, word_i);
		printf("=========================================================================\n");
	}
	printf("\tTerminate new_str[%d] with NULL\n", word_i);
	new_strs[word_i] = NULL;
	printf("\tfinal word count: %d \n", word_i);
	return (new_strs);
	printf("=========================================================================\n");
	printf("=========================================================================\n");
}
