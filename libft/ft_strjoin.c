/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:08:00 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/18 21:00:07 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	size_t	len;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	len = l1 + l2;
	join = (char *)malloc(len + 1);
	if (!join)
	{
		return (NULL);
	}
	ft_strlcpy(join, s1, l1 + 1);
	ft_strlcat(join, s2, len + 1);
	return (join);
}
