/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:21:46 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/18 17:26:46 by nchagour         ###   ########.fr       */
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
    int singleflag;
    int doubleflag;

    singleflag = 0;
    doubleflag = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == X_DQUOTE && singleflag == 0)
        {
            if (doubleflag == 0)
                doubleflag = 1;
            else
                doubleflag = 0;
        }
        else if (str[i] == X_QUOTE && doubleflag == 0)
        {
            if (singleflag == 0)
                singleflag = 1;
            else
                singleflag = 0;
        }
        i++;
    }
    if (singleflag == 1 || doubleflag == 1)
    {
        return 0;
    }
    return 1;
}
