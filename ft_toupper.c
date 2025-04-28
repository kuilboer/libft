/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/27 18:11:11 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/04/28 15:26:17 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_toupper(int c)
{
	unsigned char uc;
	uc = (unsigned char) c; // cast c as an unsigned char to handle negative input edge case
	if (c == -1) //EOF edge case
		return (-1);
	if (uc >= 'a' && uc <= 'z')
		return (uc - 32);
	return (uc);
}