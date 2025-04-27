/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:56:13 by nchagour          #+#    #+#             */
/*   Updated: 2025/04/27 22:19:18 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parsing(t_data *data)
{
    t_token *tok;
    tok = NULL;
    // data->input = readline("\n<minishell> ");
    data->input = "frehfj";
	if (!data->input)
		exit(1);
    tokens(data->input, &tok);
    if (error_start_line(tok))
    {
        write(2, "Something is wrong near line start!\n", 37);
        clean_tokens(&tok);
    }
    printtoken(tok);
    clean_tokens(&tok);
}

int main()
{
    t_data data;

    // while (1)
    // {
    //     parsing(&data);
    // }
    parsing(&data);
}
