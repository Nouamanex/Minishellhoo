/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouamane <nouamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:21:46 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/21 18:23:50 by nouamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int error_start_line(t_token *tokliste)
{
    if (!tokliste)
        return 0;
    if (tokliste->type == X_PIPE)
    {
        printf("\033[31mparse error near '|'\033[0m\n");
        return 1;
    }
    if ((tokliste->type == X_REDIR_IN || tokliste->type == X_REDIR_OUT || tokliste->type == X_HERE_DOC || tokliste->type == X_DREDIR_OUT) && (!tokliste->next || tokliste->next->type != X_WORD))
    {
        printf("error parse near %s\n", tokliste->content);
        return 1;
    }
    while (tokliste)
    {
        if (tokliste->content[0] == '|' && !tokliste->next)
        {
            printf("\033[31mparse error near '|'\033[0m\n");
            return 1;
        }
        tokliste = tokliste->next;
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
