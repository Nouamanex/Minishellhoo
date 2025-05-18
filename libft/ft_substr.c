/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:04:17 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/18 21:00:44 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*arr;
	size_t	sou_len;

	if (!s)
		return (NULL);
	sou_len = ft_strlen(s);
	if (start >= sou_len)
		return (ft_strdup(""));
	if (len > sou_len - start)
		len = sou_len - start;
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	j = 0;
	while (j < len)
	{
		arr[j] = s[start + j];
		j++;
	}
	arr[j] = '\0';
	return (arr);
}
