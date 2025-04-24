/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:24:52 by nchagour          #+#    #+#             */
/*   Updated: 2025/02/14 20:56:39 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_num(int num)
{
	size_t	i;

	i = 0;
	if (num <= 0)
	{
		i = 1;
	}
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static void	conv_to_str(char *str, long num, int len, int neg)
{
	while (len > neg)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*str;
	long	num;

	num = n;
	neg = 0;
	len = len_num(num);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		neg = 1;
		str[0] = '-';
		num = -num;
	}
	else if (num == 0)
		str[0] = '0';
	conv_to_str(str, num, len, neg);
	return (str);
}
