/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:12:15 by nchagour          #+#    #+#             */
/*   Updated: 2025/04/24 22:35:23 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// kancreer wahd token jdida bach nzidha f linked liste
t_token *create_token(char *content, int type)
{
    t_token *tok;
    tok = malloc(sizeof(t_token));
    if (!tok)
        exit(1);
    tok->content = content;
    tok->type = type;
    tok->next = NULL;
    return tok;
}

//bach nzido token f liste
void add_token(t_token **head, t_token *new)
{
	t_token *temp;

	if (!*head)
	{
		*head = new;
		return;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void printtoken(char *toprint, int start, int end)
{
    char *input;

    input = ft_substr(toprint, start, end - start);
    printf("%s\n", input);
    free(input);
}

void tokens(char *input)
{
    int i;
    int start;

    i = 0;
    start = 0;
    while (input[i])
    {
        if (is_whitespaces(input[i]))
            i++;
        else if(is_symbol(input[i]))
        {
            printtoken(input, i, i + 1);
            i++;
        }
        else
        {
            start = i;
            while (input[i] && !is_symbol(input[i]) && !is_whitespaces(input[i]))
            {
                i++;
            }
            printtoken(input, start, i);
        }
    }
    
}


