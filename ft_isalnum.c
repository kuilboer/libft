/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalphanum.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:47:26 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/04/23 15:04:41 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_isalnum(int c)
{
	return(ft_isalpha(c) || ft_isdigit(c));
}