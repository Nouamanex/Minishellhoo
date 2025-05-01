/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:12:15 by nchagour          #+#    #+#             */
/*   Updated: 2025/04/29 10:03:06 by nchagour         ###   ########.fr       */
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
    tok->content = ft_strdup(content);
    tok->type = type;
    tok->next = NULL;
    return tok;
}

//bach nzido token f liste
void	add_token(t_token **head, char *data, int type)
{
	t_token	*temp;
	t_token	*new;

	new = create_token(data, type);
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

//show tokens
void printtoken(t_token *tokliste)
{
    while (tokliste)
    {
        printf("Data --> [%s]\ntype number --> %d\n", tokliste->content, tokliste->type);
        tokliste = tokliste->next;
    }
}

//hna kandir tokens f blastha m3a type dyalha bisti3mal addtoken function
void tokens(char *input, t_token **tokliste)
{
    int i;
    int start;
    int type;
    char symbol[2];
    char *word;
    char quote;

    i = 0;
    start = 0;
    while (input[i])
    {
        if (is_whitespaces(input[i]))
            i++;
        else if(is_symbol(input[i]))
        {
           if (input[i] == '>' && input[i + 1] == '>')
            {
                word = ft_strdup(">>");
                add_token(tokliste, word, X_DREDIR_OUT);
                i += 2;
                free(word);
            }
            else if (input[i] == '<' && input[i + 1] == '<')
            {
                word = ft_strdup("<<");
                add_token(tokliste, word, X_HERE_DOC);
                i += 2;
                free(word);
            }
            else
            {
                symbol[0] = input[i];
                symbol[1] = '\0';
                if (input[i] == '|')
                    type = X_PIPE;
                else if (input[i] == '>')
                    type = X_REDIR_OUT;
                else if (input[i] == '<')
                    type = X_REDIR_IN;
                word = ft_strdup(symbol);
                add_token(tokliste, word, type);
                free(word);
                i++;
            }
        }
        else if (input[i] == '"' || input[i] == '\'')
        {
            quote = input[i];
            start = i + 1;
            ++i;
            while (input[i] && input[i] != quote)
                i++;
            word = ft_substr(input, start, i - start);
            add_token(tokliste, word, X_WORD);
            free(word);
            if (input[i] == quote)
		    i++;
        }
        else
        {
            start = i;
            while (input[i] && !is_symbol(input[i]) && !is_whitespaces(input[i]))
                i++;
            word = ft_substr(input, start, i - start);
            add_token(tokliste, word, X_WORD);
            free(word);
        }
    }
}
