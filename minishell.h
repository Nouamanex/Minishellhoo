/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:48:17 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/01 22:40:21 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
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
    X_WORD = -1 //drt -1 hit word ma3ndhach ascii number bhal lakhrin 3bbrt 3liha b -1
};

//                             ---PARCING---
//for data
typedef struct s_data
{
    char *input;
	int flag1;
}t_data;

//for tokens
typedef struct s_token {
	char *content;    // hadi kankhbi fiha hado "ls" ">" "|"..
	int type;         // hadi bach n3rf wach word ola pipe ola redirection.... drtha int hit character kan3bro 3lih b int
	struct s_token *next;
} t_token;

// for commands convert tokens into a list command
typedef struct s_command
{
	char **full_cmd; // ghanjm3 fiha dok tokens li3la chkel command
	int input_file; // file descriptor for input redirection <
	int output_file; // file descriptor for output redirection >
	struct s_command *next;
}t_command;

//some parsing helper functions
int			is_whitespaces(int c);
int			is_symbol(int c);

//tokens
void		tokens(char *input, t_token **tokliste);
void		printtoken(t_token *tokliste);
void		add_token(t_token **head, char *data, int type);

//errors
int			error_start_line(t_token *tokliste);

//cleaning
void		clean_tokens(t_token **tokliste);
void		free_cmds(t_command **cmd);

//command
t_command 	*create_cmd();
t_command *cmd_build_list(t_token *tokliste);
void print_command(t_command *list_cmd);

#endif