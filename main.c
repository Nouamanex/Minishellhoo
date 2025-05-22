/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouamane <nouamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:56:13 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/22 16:23:44 by nouamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parsing(t_data *data)
{
    t_token *tok;
    t_command *cmdlist;
    tok = NULL;
    cmdlist = NULL;
    data->input = readline("minishell$ ");
    // data->input = "jkejde || snkedn";
    add_history (data->input);
	if (!data->input)
        exit(1);
    if (!missquote(data->input))
    {
        printf("Unclosed quotes!\n");
        return;
    }
    tokens(data->input, &tok);
    replace_env(&tok);
    if (operation_errors(tok))
    {
        clean_tokens(&tok);
        return;
    }
    cmdlist = cmd_build_list(tok);
    // printtoken(tok);
    print_command(cmdlist);
    clean_tokens(&tok);
    clean_cmd(&cmdlist);
}

int main()
{
    t_data data;

    while (2002)
    {
        parsing(&data);
    }
}
