/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouamane <nouamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:29:42 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/06 17:32:24 by nouamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//working...
//mazal khdam 3liha

void replace_env(t_token **tokliste)
{
    char *str;
    int i;
    int len_str;
    char *var_env;
    char *env_value;
    int befor;
    char *strbefor;
    char *new_content;
    t_token *tmp;

    tmp = *tokliste;
    befor = 0;
    while (tmp)
    {
        str = tmp->content; //kol content kancheckih bohdo
        i = 0;
        while (str[i])
        {
            if (str[i] == '$' && str[i + 1]) // ila l9alia $ fchi kelma
            {
                befor = i; // kan39el 3la lblasa li9bel dollar hit momkin ikon 3ndi bhal haka ss$USER khess tkhrjlia ssnchagour
                i++;
                len_str = 0;
                len_str = ft_strlen(&str[i]); // kan7seb length dyal dkchi limor dollar
                var_env = ft_substr(str, i, len_str); // kan7et dakchi limor $ f var_env
                env_value = getenv(var_env); // daba dakchi likhdato var_env matalan kan USER khs tkhrjlia nchagour
                free(var_env); //safi ma3ndi mandir biha
                strbefor = ft_substr(str, 0, befor); //daba fi 7alat kant chihaja 9bel $ 7ethalia f strbefore
                if (env_value) 
                {
                    new_content = ft_strjoin(strbefor, env_value); //ila rj3atlina getenv chihaja joinihalia m3a dakchi li9bel $
                }
                else
                {
                    new_content = ft_strdup(strbefor); //sinon safi 7etlia gha dak string 3adi matalan (ss$haha) haha makaynach so khs iktblia gha ss
                }
                free(strbefor);
                free(tmp->content);
                tmp->content = new_content;
                break;
            }
            i++;
        }
        tmp = tmp->next;
    }
}
