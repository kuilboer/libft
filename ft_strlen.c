/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/25 12:45:19 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/04/28 17:33:41 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
