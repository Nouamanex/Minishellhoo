/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:56:13 by nchagour          #+#    #+#             */
/*   Updated: 2025/04/24 22:12:31 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parsing(t_data *data)
{
    data->input = readline("<minishell> ");
	if (!data->input)
	{
		exit(1);
	}
    // printf("%s\n",data->input);
    tokens(data->input);
}

int main()
{
    t_data data;

    while (1)
    {
        parsing(&data);
    }
}