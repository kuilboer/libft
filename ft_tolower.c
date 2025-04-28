/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/27 18:11:04 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/04/28 15:24:51 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_tolower(int c)
{
	unsigned char uc;
	uc = (unsigned char) c; // cast c as an unsigned char to handle negative input edge case
	if (c == -1) //EOF edge case
		return (-1);
	if (uc >= 'A' && uc <= 'Z')
		return (uc + 32);
	return (uc);
}