/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouamane <nouamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:29:42 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/06 17:01:52 by nouamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//working...
//mazal khdam 3liha

// void replace_env(t_token **tokliste)
// {
//     char *str;
//     int i;
//     int j;
//     int len_str;
//     char *var_env;
//     char *env_value;
//     int befor;
//     char *strbefor;
//     char *total;

//     befor = 0;
//     j = 0;
//     while (*tokliste)
//     {
//         str = (*tokliste)->content;
//         i = 0;
//         while (str[i])
//         {
//             if (str[i] == '$' && str[i + 1])
//             {
//                 befor = i;
//                 i++;
//                 len_str = 0;
//                 len_str = ft_strlen(&str[i]);
//                 var_env = ft_substr(str, i, len_str);
//                 env_value = getenv(var_env);
//                 free(var_env);
//                 if (befor > 0)
//                 {
//                     j = 0;
//                     while (j < befor)
//                     {
//                         strbefor[j] = str[j];
//                         j++;
//                     }
//                 }
//                 if (env_value)
//                 {
//                     free((*tokliste)->content);
//                     (*tokliste)->content = ft_strdup(env_value);
//                 }
//                 break;
//             }
//             i++;
//         }
//         tokliste = &(*tokliste)->next;
//     }
// }
