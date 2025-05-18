/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:29:42 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/18 20:44:38 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//working...

size_t	ft_strlen_env(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && (ft_isalnum(s[i]) || s[i] == '_'))
	{
		i++;
	}
	return (i);
}

void expand_helper(t_token **toklist) //had lfunction drtha 7it kaykhsni nchecki wach dakchi li9dam dollar mcloser b quotes bach it7yd dollar sinon ayb9a ,!!khdmt biha f replace_env()
{
    t_token *temp;
    t_token *before;

    temp = *toklist;
    before = NULL;
    if (temp && temp->content && temp->content[0] == '$' && temp->content[0] =='\0')
    {
        if (temp->next && temp->next->flag_quote > 0)
        {
            *toklist = temp->next;
            free(temp);
            return;
        }
    }
    while (temp && temp->next && temp->content && (*temp->content) != '$')
    {
        before = temp;
        temp = temp->next;
    }
    if (!temp)
    {
        return;
    }
    if (temp->next && temp->next->flag_quote > 0)
    {
        if (before)
        {
            before->next = temp->next;
        }
        else
        {
            *toklist = temp->next;
        }
    }
}

void replace_env(t_token **tokliste)
{
    t_token *tmp;
    char *str; // kankhbi fiha string dyali li f token
    char *resultstr; //result dyali lighan7tha f token blast dakchi likan fih
    char *strbefore; //dakchi li9bel $
    char *strvar; //dakchi limor $ kanchecki wach dakhl f env okan7t result f getenv
    char *envvalue; //dakchi lirj3atlia getenv matalan nchagour
    int i;
    int j;
    int var_len; //katakhdlia length dyal dakchi limor $ 3la wdit substr

    
    tmp = *tokliste;
    while (tmp)
    {
        if (tmp->flag_quote == 1)
        {
            tmp = tmp->next; //ila kant fhad token '' safi gha n9zha hit ma kat expandach b $
            continue; //safi rje3 3awd matkemelch
        }
        str = tmp->content; // bayna :)
        i = 0; 
        resultstr = ""; // bach first join madirch mochkil
        while (str[i]) //kandor 3la string dyali
        {
            if (str[i] == '$' && str[i + 1] && (ft_isalnum(str[i + 1]) || str[i + 1] == '_')) //l9it wahd dollar
            {
                strbefore = ft_substr(str, 0, i); //dakchi li9bel $ 7etolia hna
                resultstr = ft_strjoin(resultstr, strbefore); // joinilia dakchi lil9iti m3a result
                j = i + 1; //bach nfot $
                var_len = ft_strlen_env(&str[j]); //hssblia length dyal dakchi limor $
                strvar = ft_substr(str, j, var_len); // 7etolia hna bach nsifto l getenv
                envvalue = getenv(strvar); // sifto db l getenv
                if (envvalue) //ila l9iti chihaja
                {
                    resultstr = ft_strjoin(resultstr, envvalue); //joinilia dkchi likhrjlia m3a result kil3ada
                }
                i = j + var_len; //i daba khsha tskipi dkchi kaml bach khdemna bach nupdati string dyali bach nkml bih lkhdma
                str = &str[i]; //$USER$PATH = $PATH
                i = 0;
            }
            else{
                i++;
            }
        }
        resultstr = ft_strjoin(resultstr, str);
        tmp->content = resultstr;
        tmp = tmp->next;
    }
        expand_helper(tokliste);
}
