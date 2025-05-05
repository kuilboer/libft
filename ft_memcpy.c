/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/04 19:48:52 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/05 13:42:52 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d_buf;
	unsigned char	*s_buf;

	if (!dest && !src)
		return (NULL);
	d_buf = (unsigned char *)dest;
	s_buf = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d_buf[i] = s_buf[i];
		i++;
	}
	return ((void *)dest);
}