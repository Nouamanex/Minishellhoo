/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:39:32 by nchagour          #+#    #+#             */
/*   Updated: 2025/02/14 20:57:34 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldest;
	size_t	lsrc;
	size_t	i;

	lsrc = ft_strlen(src);
	if (!dst && size == 0)
		return (lsrc);
	i = 0;
	ldest = ft_strlen((const char *)dst);
	if (size <= ldest)
	{
		return (lsrc + size);
	}
	while (src[i] && (i + ldest < size - 1))
	{
		dst[i + ldest] = src[i];
		i++;
	}
	dst[i + ldest] = '\0';
	return (lsrc + ldest);
}
