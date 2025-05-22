/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:04:37 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/22 23:09:29 by nchagour         ###   ########.fr       */
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

char* checkDollar(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '$')
        {
            i++;
            return str + i;
        }
        i++;
    }
    return NULL;
}

int tokens_size(t_token *tok)
{
    int count;

    count = 0;
    while (tok)
    {
        count++;
        tok = tok->next;
    }
    return count;
}

int is_operator(int type)
{
    return (type == X_PIPE || type == X_REDIR_IN || type == X_REDIR_OUT
        || type == X_DREDIR_OUT || type == X_HERE_DOC);
}

int is_redir(int type)
{
    return (type == X_REDIR_IN || type == X_REDIR_OUT || type == X_DREDIR_OUT || type == X_HERE_DOC);
}