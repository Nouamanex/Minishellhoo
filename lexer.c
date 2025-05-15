/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouamane <nouamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:12:15 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/15 02:08:19 by nouamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// kancreer wahd token jdida bach nzidha f linked liste
t_token *create_token(char *content, int type, int flag)
{
    t_token *tok;
    
    tok = malloc(sizeof(t_token));
    if (!tok)
        exit(1);
    tok->content = ft_strdup(content);
    tok->type = type;
    tok->next = NULL;
    tok->flag_quote = flag;
    return tok;
}

//bach nzido token f liste
void	add_token(t_token **head, char *data, int type, int flag)
{
	t_token	*temp;
	t_token	*new;

	new = create_token(data, type, flag);
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
        printf("Data --> [%s]\ntype number --> %d\nflag --> %d\n", tokliste->content, tokliste->type, tokliste->flag_quote);
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
    int flag;

    i = 0;
    flag = 0;
    start = 0;
    // if (!missquote(input))
    // {
    //     printf("the quotes are not closed!!\n");
    //     exit(1);
    // }
    while (input[i])
    {
        if (is_whitespaces(input[i]))
            i++;
        else if(is_symbol(input[i]))
        {
           if (input[i] == '>' && input[i + 1] == '>')
            {
                word = ft_strdup(">>");
                flag = 0;
                add_token(tokliste, word, X_DREDIR_OUT, flag);
                i += 2;
                free(word);
            }
            else if (input[i] == '<' && input[i + 1] == '<')
            {
                word = ft_strdup("<<");
                flag = 0;
                add_token(tokliste, word, X_HERE_DOC, flag);
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
                flag = 0;
                add_token(tokliste, word, type, flag);
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
            if (input[i] == '\'')
                flag = 1;
            add_token(tokliste, word, X_WORD, flag);
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
            flag = 0;
            add_token(tokliste, word, X_WORD, flag);
            free(word);
        }
    }
}
