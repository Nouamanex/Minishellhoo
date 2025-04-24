/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:14:25 by nchagour          #+#    #+#             */
/*   Updated: 2025/03/07 00:34:08 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	le;

	le = size * nmemb;
	arr = malloc(le);
	if (!arr)
	{
		return (NULL);
	}
	ft_bzero(arr, le);
	return (arr);
}
