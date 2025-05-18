/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:29:48 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/18 21:00:40 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ver(char c, const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	e;
	size_t	len;
	char	*arr;

	if (!s1)
		return (NULL);
	s = 0;
	e = ft_strlen(s1);
	while (s1[s] && ft_ver(s1[s], set) == 1)
		s++;
	while (e > s && ft_ver(s1[e - 1], set) == 1)
		e--;
	len = e - s;
	arr = ft_substr(s1, s, len);
	if (!arr)
		return (NULL);
	return (arr);
}
