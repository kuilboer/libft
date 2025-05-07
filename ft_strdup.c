/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 14:51:34 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/07 17:55:09 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		s_len;

	s_len = ft_strlen(s);
	new_str = malloc((s_len + 1) * sizeof(char));
	if (!new_str)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_strlcpy(new_str, s, (s_len + 1));
	return (new_str);
}
