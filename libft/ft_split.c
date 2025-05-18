/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:48:50 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/18 20:59:50 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cw(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
		{
			i++;
		}
		if (str[i])
		{
			count++;
		}
		while (str[i] && str[i] != c)
		{
			i++;
		}
	}
	return (count);
}

static size_t	ft_strlenc(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}

char	**ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	*ft_strdupc(const char *s, char c)
{
	int		len;
	char	*arr;

	len = ft_strlenc(s, c) + 1;
	arr = (char *)malloc(len * sizeof(char));
	if (arr == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(arr, s, len);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_cw(s, c) + 1));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			arr[x] = ft_strdupc(&s[i], c);
			if (!arr[x])
				return (ft_free(arr));
			x++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	arr[x] = NULL;
	return (arr);
}
