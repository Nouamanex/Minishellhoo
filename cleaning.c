/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:59:22 by nchagour          #+#    #+#             */
/*   Updated: 2025/04/27 20:40:39 by nchagour         ###   ########.fr       */
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
		free(temp);
	}
}