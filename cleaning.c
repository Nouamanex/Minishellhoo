/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:59:22 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/02 19:09:49 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_tokens(t_token **tokliste)
{
	t_token	*temp;

	while (*tokliste)
	{
		temp = *tokliste;
		*tokliste = (*tokliste)->next;
		free(temp->content);
		free(temp);
	}
}

void free_fullcmd(t_command *cmd)
{
    int i = 0;
    if (!cmd->full_cmd)
        return;
    while (cmd->full_cmd[i])
    {
        free(cmd->full_cmd[i]);
        i++;
    }
    free(cmd->full_cmd);
}

void clean_cmd(t_command **cmd)
{
    t_command *temp;

    while (*cmd)
    {
        temp = *cmd;
        *cmd = (*cmd)->next;
        free_fullcmd(temp);
        free(temp);
    }
}
