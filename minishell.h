/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:48:17 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/22 01:04:05 by nchagour         ###   ########.fr       */
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

                            //---PARCING---
//for data
typedef struct s_data
{
    char *input;
}t_data;

//for tokens
typedef struct s_token {
	char *content;    // hadi kankhbi fiha hado "ls" ">" "|"..
	int type;         // hadi bach n3rf wach word ola pipe ola redirection.... drtha int hit character kan3bro 3lih b int
	int flag_quote;
	struct s_token *next;
} t_token;

// for commands convert tokens into a list command
typedef struct s_command
{
	char **full_cmd; // ghanjm3 fiha dok tokens li3la chkel command
	int input_file; // file descriptor for input redirection <
	int output_file; // file descriptor for output redirection >
	struct s_command *next;
}t_command; //!!!bnisba l hadi rah kayna case dyal echo nouamane>file1.txt>file2.txt  ya3ni 3ndna 2 files!! 
			//so hna ach kaytra rah kay7el lfile lwel okayclosih makayktb fih walo o akhir wahd howa fach kaykteb howa likankhbi fd dyalo!
			//lprob li3ndi howa anaho mol execution fach ghaybghi idir fork ghaywliw 3ndna 2 processes

//some parsing helper functions
int			is_whitespaces(int c);
int			is_symbol(int c);
char* 		checkDollar(char *str);
int 		tokens_size(t_token *tok);
int 		is_operator(int type);

//tokens
void		tokens(char *input, t_token **tokliste);
void		printtoken(t_token *tokliste);
void		add_token(t_token **head, char *data, int type, int flag);
void		replace_env(t_token **tokliste);

//command
t_command 	*create_cmd();
t_command *cmd_build_list(t_token *tokliste);
void print_command(t_command *list_cmd);

//cleaning
void		clean_tokens(t_token **tokliste);
void		clean_cmd(t_command **cmd);

//errors
//int			error_start_line(t_token *tokliste);
int 		missquote(char *str);
int 		operator_error(t_token *tokens);
int 		operation_errors(t_token *tokliste);

#endif