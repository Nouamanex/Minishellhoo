/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouamane <nouamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:21:46 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/15 02:05:39 by nouamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int error_start_line(t_token *tokliste)
{
    if (!tokliste)
        return 0;
    if (tokliste->type == X_PIPE)
    {
        return 1;
    }
    if ((tokliste->type == X_REDIR_IN || tokliste->type == X_REDIR_OUT || tokliste->type == X_HERE_DOC || tokliste->type == X_DREDIR_OUT) && (!tokliste->next || tokliste->next->type != X_WORD))
    {
        return 1;
    }
    return 0;
}

int missquote(char *str)
{
    int i;
    int count;
    
    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == X_DQUOTE || str[i] == X_QUOTE)
            count++;
        i++;
    }
    if (count % 2 != 0)
    {
        return 0;
    }
    return 1;
}