/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 17:53:26 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/04/28 21:27:59 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (1) // run forever.
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
			if (s[i] == '\0')
			break; // break out of the loop at the end of the string.
		i++;
	}
	return (0);
}