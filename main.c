/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouamane <nouamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:56:13 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/07 18:00:58 by nouamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parsing(t_data *data)
{
    t_token *tok;
    t_command *cmdlist;
    // char *env_test;
    tok = NULL;
    cmdlist = NULL;
    data->input = readline("<minishell> ");
    // data->input = "ls -l | ls -l"; //hadi bach nchecki leaks makankhdmch b readline
	if (!data->input)
        exit(1);
    tokens(data->input, &tok);
    replace_env(&tok);
    cmdlist = cmd_build_list(tok);
    if (error_start_line(tok))
    {
        write(2, "Something is wrong near line start!\n", 37);
        clean_tokens(&tok);
    }
    printtoken(tok);
    clean_tokens(&tok);
    clean_cmd(&cmdlist);
}

int main()
{
    t_data data;

    while (1)
    {
        parsing(&data);
    }
    // parsing(&data);
}
