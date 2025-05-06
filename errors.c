/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouamane <nouamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:21:46 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/06 17:47:23 by nouamane         ###   ########.fr       */
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

int error_quotes(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == "'")
        {
            
        }
    }
    
}
