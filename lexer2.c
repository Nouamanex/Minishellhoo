/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:57:09 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/22 23:51:02 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//bach nmalloci l dik la command o n initialiser data dyalha
t_command *create_cmd()
{
    t_command *cmd;

    cmd  = malloc(sizeof(t_command));
    if (!cmd)
        return NULL;
    cmd->full_cmd = NULL;
    cmd->next = NULL;
    cmd->next = NULL;
    return  cmd;
}

// add arg to other args bach nkmel command
void add_arg(t_command *cmd, char *arg)
{
    int i;
    char **new_args;

    i = 0;
    if (cmd->full_cmd)
        while (cmd->full_cmd[i])
            i++;
    new_args = malloc(sizeof(char *) * (i + 2));//+2 hit khsni nzid arg jdid + NULL flkhr
    if (!new_args)
        return;

    i = 0;
    while (cmd->full_cmd && cmd->full_cmd[i]) {
        new_args[i] = cmd->full_cmd[i];
        i++;
    }
    new_args[i++] = strdup(arg);
    new_args[i] = NULL;
    free(cmd->full_cmd);
    cmd->full_cmd = new_args;
}

// add command to the liste
void add_command(t_command **liste_cmd, t_command *new_cmd)
{
    t_command *temp;

    if (!*liste_cmd)
    {
        *liste_cmd = new_cmd;
        return;
    }
    temp = *liste_cmd;
    while (temp->next)
        temp = temp->next;
    temp->next = new_cmd;
}

//lfunction li3liha kolchi
t_command *cmd_build_list(t_token *tokliste)
{
    t_command *liste_cmd;
    t_command *cmd;
    t_redir   *new_redir;
    int redir_type;

    liste_cmd = NULL;
    cmd = NULL;
    while (tokliste)
    {
        if (!cmd) //fkol mra dkhlt command kanrdo null bach idkhl tani hna wibda ijm3lia command tani mn lwl
        {
            cmd = create_cmd();
            if(!cmd)
                return NULL;
        }
        if (tokliste->type == X_WORD) //check ila kan word olakhrin ila kano hajat akhrin
        {
            add_arg(cmd, tokliste->content); // zido 3la words lakhrin bach nkmel command
        }
        else if (tokliste->type == X_PIPE)
        {
            add_command(&liste_cmd, cmd);// ila kan pipe kay3ni bli salit la command o daba khassni nzidha f liste
            cmd = NULL; // bach nwjed l lcommand jaya
        }else if (is_redir(tokliste->type))
        {
            redir_type = tokliste->type;
            tokliste = tokliste->next;
            if (tokliste && tokliste->type == X_WORD)
            {
                new_redir = create_redir(redir_type, tokliste->content);
                add_redir(&(cmd->redir), new_redir);
            }
        }
        tokliste = tokliste->next;
    }
    if (cmd)// n9der nsali command bla pipe aykhsni nchecki bli 3mrt command safi zidhalia f liste wsf returniha
    {
        add_command(&liste_cmd, cmd);
    }
    return liste_cmd;
}

void print_command(t_command *cmds)
{
    int i;
    t_redir *redir;

    while (cmds)
    {
        printf("Command:\n");
        i = 0;
        while (cmds->full_cmd && cmds->full_cmd[i])
        {
            printf("Arg[%d]: %s\n", i, cmds->full_cmd[i]);
            i++;
        }
        redir = cmds->redir;
        while (redir)
        {
            if (redir->type == X_HERE_DOC)
            {
                printf("type : << , File : [%s]\n", redir->filename);// hadi HEREDOC
            }
            else if (redir->type == X_DREDIR_OUT)
            {
                printf("type : >> , FILE : [%s]\n", redir->filename); // hadi Append Redir Output
            }
            else if (redir->type == X_REDIR_IN)
            {
                printf("type : < , File : [%s]\n", redir->filename); // hadi redir input
            }
            else if (redir->type == X_REDIR_OUT)
            {
                 printf("type : > , File : [%s]\n", redir->filename); // hadi redir output
            }
            redir = redir->next;
        }
        cmds = cmds->next;
    }
}
