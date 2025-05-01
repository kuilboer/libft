/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/25 12:29:15 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/01 15:27:55 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

#define LIBFT_H

#include <stddef.h>

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int 			ft_tolower(int c);
int				ft_toupper(int c);
unsigned int	ft_strlen(const char *s);
char 			*ft_strchr(const char *s, int c);
char 			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void 			*ft_memset(void *s, int c, unsigned int n);

/*
ft_memset
ft_bzero
ft_memcpy
ft_memmove
ft_strlcpy
ft_strlcat
ft_toupper
ft_tolower
ft_strchr
ft_strrchr
ft_strncmp
ft_memchr
ft_memcmp
ft_strnstr
ft_atoi
*/
#endif
