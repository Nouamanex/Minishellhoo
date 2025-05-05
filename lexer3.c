/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:29:42 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/05 21:09:04 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//working...

void replace_env(t_token **tokliste)
{
    char *str;
    int i;
    int len_str;
    char *var_env;
    char *env_value;

    while (*tokliste)
    {
        str = (*tokliste)->content;
        i = 0;
        while (str[i])
        {
            if (str[i] == '$' && str[i + 1])
            {
                i++;
                len_str = 0;
                len_str = ft_strlen(&str[i]);
                var_env = ft_substr(str, i, len_str);
                env_value = getenv(var_env);
                free(var_env);
                if (env_value)
                {
                    free((*tokliste)->content);
                    (*tokliste)->content = ft_strdup(env_value);
                }
                break; // stop after first env replacement
            }
            i++;
        }
        tokliste = &(*tokliste)->next;
    }
}


// void    env_get(t_token *tokliste)
// {
//     char *afterDollar;
//     char *get_env;
//     afterDollar = NULL;
//     get_env = NULL;
//     while (tokliste)
//     {
//         if (tokliste->type == X_WORD && checkDollar(tokliste->content))
//         {
//             afterDollar = checkDollar(tokliste->content);
//             get_env = getenv(afterDollar);
//             (*tokliste)->content = get_env;
//         }
//         (*tokliste) = (*tokliste)->next;
//     }
//     // return get_env;
// }
