/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:56:13 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/01 22:39:53 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parsing(t_data *data)
{
    t_token *tok;
    t_command *cmdlist;
    tok = NULL;
    cmdlist = NULL;
    data->input = readline("\n<minishell> ");
    // data->input = "ls -l"; hadi bach nchecki leaks makankhdmch b readline
	if (!data->input)
        exit(1);
    tokens(data->input, &tok);
    cmdlist = cmd_build_list(tok);
    if (error_start_line(tok))
    {
        write(2, "Something is wrong near line start!\n", 37);
        clean_tokens(&tok);
    }
    print_command(cmdlist);
    clean_tokens(&tok);
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
