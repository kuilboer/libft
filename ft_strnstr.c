/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/29 19:28:39 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/04/29 20:50:59 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	big_i;
	size_t	lit_i;

	if ( *little == "")
		return (big);
	i = 0;
	while(i < len)
	{
		big_i = i;
		lit_i = 0;
		while(little[lit_i] == big[big_i])
		{
			if (little[lit_i] == '\0')
				return((char *)big[i]);
			if (big_i >= len)
				break;
			lit_i++;
			big_i++;
		}
		if (big[big_i] == '\0')
			return (0);
		i++;
	}
}