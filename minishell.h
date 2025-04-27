/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:48:17 by nchagour          #+#    #+#             */
/*   Updated: 2025/04/27 20:40:54 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/history.h>
#include <readline/readline.h>

//wahd enum bach tshel 3lina lkhdma
enum e_type
{
    X_SPACE = ' ',
	X_NEW_LINE = '\n',
	X_QUOTE = '\'',
	X_DQUOTE = '\"',
	X_DOLLAR = '$',
	X_PIPE = '|',
	X_REDIR_IN = '<',
	X_REDIR_OUT = '>',
	X_DREDIR_OUT,  // >> 
	X_HERE_DOC , // <<
    X_WORD = -1, //drt -1 hit word ma3ndhach ascii number bhal lakhrin 3bbrt 3liha b -1
	OR,
	AND
};

typedef struct s_data
{
    char *input;
}t_data;

typedef struct s_token {
	char *content;    // hadi kankhbi fiha hado "ls" ">" "|"..
	int type;         // hadi bach n3rf wach word ola pipe ola redirection.... drtha int hit character kan3bro 3lih b int
	struct s_token *next;
} t_token;

int		is_whitespaces(int c);
int		is_symbol(int c);
void	tokens(char *input, t_token **tokliste);
void	printtoken(t_token *tokliste);
void	add_token(t_token **head, char *data, int type);
int		error_start_line(t_token *tokliste);
void	clean_tokens(t_token **tokliste);