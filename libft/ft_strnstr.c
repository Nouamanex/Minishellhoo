/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:18:40 by nchagour          #+#    #+#             */
/*   Updated: 2025/02/14 20:57:51 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big && !len)
		return (NULL);
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while ((i + j) < len && big[i + j] == little[j]
			&& big[i + j] && little[j])
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
