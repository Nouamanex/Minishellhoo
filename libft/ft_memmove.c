/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:04:11 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/18 20:59:31 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*sr;
	char	*de;

	sr = (char *)src;
	de = (char *)dest;
	if (sr < de)
	{
		while (n--)
		{
			de[n] = sr[n];
		}
	}
	else
	{
		ft_memcpy(de, sr, n);
	}
	return (de);
}
