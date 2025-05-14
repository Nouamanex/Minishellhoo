/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouamane <nouamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:29:42 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/14 22:39:44 by nouamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//working...
//mazal khdam 3liha

size_t	ft_strlen_env(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '$')
	{
		i++;
	}
	return (i);
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
            if (str[i] == '$' && str[i + 1]) //l9it wahd dollar
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
}