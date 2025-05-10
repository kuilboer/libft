/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 21:59:13 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/08 14:43:09 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int is_in_set(char c , char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++; 
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	start_c;
	size_t	end_c;
	size_t	len;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start_c = 0;
	while (s1[start_c] && is_in_set(s1[start_c], set))
		start_c++;
	end_c = start_c;
	while (s1[end_c] && !is_in_set(s1[end_c], set))
		end_c++;
	len = (end_c - start_c);
	new_str = malloc((len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = s1[start_c + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}