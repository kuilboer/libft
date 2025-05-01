/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/29 19:28:39 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/01 14:13:41 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	big_i;
	size_t	lit_i;

	if ( *little == '\0')
		return ((char *)big);
	i = 0;
	while(i < len)
	{
		big_i = i;
		lit_i = 0;
		if (big[i] == little[0])
		{
			while(little[lit_i])
			{
				if (big_i >= len || !big[big_i])
					return (0);
				if (big[big_i] != little[lit_i])
					break;
				lit_i++;
				big_i++;
			}
			if (!little[lit_i])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}