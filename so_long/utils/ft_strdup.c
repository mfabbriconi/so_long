/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:33:07 by mfabbric          #+#    #+#             */
/*   Updated: 2023/04/05 16:12:08 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(char *s)
{
	size_t	len_s;
	char	*s2;

	len_s = ft_strlen(s);
	s2 = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!s2)
		return (0);
	ft_memcpy(s2, s, (len_s + 1));
	return (s2);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char			*d;
	const unsigned char		*s;

	d = dst;
	s = src;
	if (!dst && !src)
		return (0);
	while (len-- > 0)
		*d++ = *s++;
	return (dst);
}
