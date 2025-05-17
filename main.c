/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:56:13 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/17 17:32:16 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parsing(t_data *data)
{
    t_token *tok;
    t_command *cmdlist;
    tok = NULL;
    cmdlist = NULL;
    data->input = readline("<minishell> ");
    add_history (data->input);
	if (!data->input)
        exit(1);
    if (!missquote(data->input))
    {
        printf("Unclosed quotes!\n");
        free(data->input);
        return;
    }
    tokens(data->input, &tok);
    replace_env(&tok);
    cmdlist = cmd_build_list(tok);
    if (error_start_line(tok))
    {
        write(2, "Something is wrong near line start!\n", 37);
        clean_tokens(&tok);
    }
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
