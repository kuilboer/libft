/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/29 14:48:22 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/04/29 15:32:22 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"
#include <stdio.h>

char *ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = 0;
	while (1) // run forever to also catch '/0' edge case.
	{
		if (*s == (char)c)
		{
			ptr = (char*)s;
		}
		if (*s == '\0')
			break; // break out of the loop at the end of the string.
		s++;
	}
	return (ptr);
	
}