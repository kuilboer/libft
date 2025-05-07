/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/29 19:28:39 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/07 13:20:25 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_needle(const char *big, const char *little, \
	size_t big_i, size_t len)
{
	int	lit_i;

	lit_i = 0;
	while (little[lit_i])
	{
		if (big_i >= len || !big[big_i])
			return (0);
		if (big[big_i] != little[lit_i])
			return (0);
		lit_i++;
		big_i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (i < len)
	{
		if (big[i] == little[0])
		{
			if (is_needle(big, little, i, len))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
