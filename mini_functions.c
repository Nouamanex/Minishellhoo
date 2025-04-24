/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:04:37 by nchagour          #+#    #+#             */
/*   Updated: 2025/04/24 21:01:13 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_whitespaces(int c)
{
    if (c == ' ' ||(c >= 9 && c <= 13))
        return 1;
    return 0;
}

int is_symbol(int c)
{
    if (c == '|' || c == '<' || c == '>')
        return 1;
    return 0;
}

